#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int mp[N][N],vis[N][N],sum[N][N],dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,m,mxx,mix,mxy,miy;
void dfs(int x,int y){
    if(vis[x][y]||!mp[x][y])return;
    vis[x][y]=1;
    mxx=max(mxx,x);
    mix=min(mix,x);
    mxy=max(mxy,y);
    miy=min(miy,y);
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        dfs(nx,ny);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(vis,0,sizeof vis);
        memset(mp,0,sizeof mp);
        for(int i=1;i<=n;i++){
            for(int o=1;o<=m;o++){
                scanf("%1d",&mp[i][o]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int o=1;o<=m;o++){
                sum[i][o]=sum[i-1][o]+sum[i][o-1]-sum[i-1][o-1]+mp[i][o];
            }
        }
        int cnt=0,pd=0;
        for(int i=1;i<=n;i++)
        for(int o=1;o<=m;o++){
            if(mp[i][o]&&!vis[i][o]){
                mxx=0,mix=1e9,mxy=0,miy=1e9;
                dfs(i,o);
                if(sum[mxx][mxy]-sum[mxx][miy-1]-sum[mix-1][mxy]+sum[mix-1][miy-1]!=(mxx-mix+1)*(mxy-miy+1))pd=1;
            }
        }
        puts(pd?"NO":"YES");
    }
    return  0;
}