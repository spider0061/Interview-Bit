bool valid(int i,int j,int A,int B){
    if(i>=1 && i<=A && j>=1 && j<=B)return true;
    return false;
}
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int vis[A+1][B+1];
    for(int i=0;i<=A;i++){
        for(int j=0;j<=B;j++){
            vis[i][j]=INT_MAX;
        }
    }
    int X[]={-2,-2,2,2,1,1,-1,-1};
    int Y[]={-1,1,-1,1,-2,2,-2,2};
    queue<pair<int,int>> q;
    vis[C][D]=0;
    q.push({C,D});
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            if(valid(x+X[i],y+Y[i],A,B) and vis[x+X[i]][y+Y[i]]==INT_MAX){
                vis[x+X[i]][y+Y[i]]=1+vis[x][y];
                q.push({x+X[i],y+Y[i]});
            }
        }
    }
    if(vis[E][F]!=INT_MAX){
        return vis[E][F];
    }
    return -1;
}
