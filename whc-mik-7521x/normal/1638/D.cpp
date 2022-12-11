#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int dx[]={-1,-1,-1,0,0,0,1,1,1},dy[]={-1,0,1,-1,0,1,-1,0,1};
int mp[N][N],n,m,vis[N][N];
bool pd(int x,int y){
    return x>=1&&y>=1&&x<n&&y<m;
}
bool check(int x,int y){
    int now=max(mp[x][y],max(mp[x][y+1],max(mp[x+1][y],mp[x+1][y+1])));
    return (mp[x][y]==now||mp[x][y]==0)&&(mp[x+1][y]==now||mp[x+1][y]==0)&&(mp[x][y+1]==now||mp[x][y+1]==0)&&(mp[x+1][y+1]==now||mp[x+1][y+1]==0);
}
int colo(int x,int y){
    return max(max(mp[x][y],max(mp[x][y+1],max(mp[x+1][y],mp[x+1][y+1]))),1);
}
struct node{
    int x,y,co;
};
int main(){
    stack<node>ans;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int o=1;o<=m;o++){
            scanf("%d",&mp[i][o]);
        }
    }
    queue<pair<int,int>>q;
    for(int i=1;i<n;i++){
        for(int o=1;o<m;o++){
            if(check(i,o))q.push({i,o});
        }
    }
    while(q.size()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        if(vis[x][y])continue;
        vis[x][y]=1;
        ans.push({x,y,colo(x,y)});
        mp[x][y]=mp[x][y+1]=mp[x+1][y]=mp[x+1][y+1]=0;
        for(int i=x;i<=x+1;i++){
            for(int o=y;o<=y+1;o++){
                int xx=i,yy=o;
                for(int j=0;j<9;j++){
                    int nx=xx+dx[j],ny=yy+dy[j];
                    if(pd(nx,ny)&&check(nx,ny))q.push({nx,ny});
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int o=1;o<=m;o++){
            if(mp[i][o]){
                return puts("-1"),0;
            }
        }
    }
    printf("%d\n",(int)ans.size());
    while(ans.size()){
        printf("%d %d %d\n",ans.top().x,ans.top().y,ans.top().co);
        ans.pop();
    }
    return  0;
}