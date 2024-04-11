#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+9;
const int M = 49;
const int Q = 1e5+9;
const int E = 2e6+9;
const int inf = 1e9;
int n,m,k,ask,a[N][N],head[N*N],tot,c[M];
struct pp{int nxt,to;}g[E];
void add(int u,int v){
    g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
int pos(int x,int y){return (x-1)*m+y;}
int dis[M][N*N],vis[M];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
queue<int >q;
void bfs(int col){
    int u=c[col];dis[col][u]=0;
    while(!q.empty()) q.pop();
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;q.push(v);
        dis[col][v]=0;
    }
    memset(vis,0,sizeof(vis));vis[col]=1;
    while(!q.empty()){
        u=q.front();q.pop();
        int x=(u-1)/m+1;int y=u-(x-1)*m;
        if(x<=n&&x>=1&&y<=m&&y>=1){
            for(int i=0;i<4;i++){
                int nx=dx[i]+x,ny=dy[i]+y;
                if(nx>n||nx<1||ny>m||ny<1) continue;
                if(dis[col][pos(nx,ny)]==-1||dis[col][pos(nx,ny)]>dis[col][u]+1){
                    dis[col][pos(nx,ny)]=dis[col][u]+1;
                    q.push(pos(nx,ny));
                }
            }
        }
        if(vis[a[x][y]]) continue;vis[a[x][y]]=1;
        for(int i=head[c[a[x][y]]];i!=-1;i=g[i].nxt){
            int v=g[i].to;
            if(dis[col][v]==-1||dis[col][v]>dis[col][u]+1){
                dis[col][v]=dis[col][u]+1;
                q.push(v);
            }
        }
    }
    return ;
}
int main(){
    memset(head,-1,sizeof(head));
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=k;i++) c[i]=n*m+i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) add(c[a[i][j]],pos(i,j));
    memset(dis,-1,sizeof(dis));
    for(int i=1;i<=k;i++) bfs(i);   
    scanf("%d",&ask);
    while(ask--){
        int xr,xc,yr,yc,ans=inf;
        scanf("%d%d%d%d",&xr,&xc,&yr,&yc);
        ans=min(ans,abs(xr-yr)+abs(xc-yc));
        for(int i=1;i<=k;i++)
            if(dis[i][pos(xr,xc)]!=-1&&dis[i][pos(yr,yc)]!=-1){
                ans=min(ans,dis[i][pos(xr,xc)]+dis[i][pos(yr,yc)]+1);
            }
        printf("%d\n",ans);
    }
    return 0;
}