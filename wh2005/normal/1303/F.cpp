#include<bits/stdc++.h>
using namespace std;
#define id(x,y) ((x-1)*m+y)
#define pb push_back
const int N = 2e6+9;
const int M = 3e2+9;
int n,m,q,a[M][M],ans[N];
struct node{
    int tim,x,y;
    node(int tt=0,int xx=0,int yy=0){tim=tt,x=xx,y=yy;}
};
vector<node >p[N],g[N];
int f[N];
int find(int x){return x==f[x]?x:(f[x]=find(f[x]));}
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int main(){
    scanf("%d%d%d",&n,&m,&q);
    int V=0;
    for(int i=1;i<=q;i++){
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        if(a[x][y]!=z){
            g[a[x][y]].pb(node(i,x,y));a[x][y]=z;p[z].pb(node(i,x,y));
        }
        V=z;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) g[a[i][j]].pb(node(q+1,i,j));
    memset(a,0,sizeof(a));
    for(int i=1;i<=V;i++){
        for(int j=0;j<(int)p[i].size();j++){
            node e=p[i][j];f[id(e.x,e.y)]=id(e.x,e.y);
        }
        for(int j=0;j<(int)p[i].size();j++){
            node e=p[i][j];int x=e.x,y=e.y;a[x][y]=i;
            int dt=1;
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx<1||nx>n||ny<1||ny>m) continue;
                if(a[x][y]==a[nx][ny]){
                    int fu=find(id(x,y)),fv=find(id(nx,ny));
                    if(fu!=fv){f[fu]=fv;dt--;}
                }
            }
            ans[e.tim]+=dt;
        }
    }
    memset(a,-1,sizeof(a));
    for(int i=0;i<=V;i++){
        for(int j=(int)g[i].size()-1;j>=0;j--){
            node e=g[i][j];f[id(e.x,e.y)]=id(e.x,e.y);
        }
        for(int j=(int)g[i].size()-1;j>=0;j--){
            node e=g[i][j];int x=e.x,y=e.y;a[x][y]=i;
            int dt=1;
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx<1||nx>n||ny<1||ny>m) continue;
                if(a[x][y]==a[nx][ny]){
                    int fu=find(id(x,y)),fv=find(id(nx,ny));
                    if(fu!=fv){f[fu]=fv;dt--;}
                }
            }
            ans[e.tim]-=dt;
        }
    }
    for(int i=1;i<=q;i++) ans[i]+=ans[i-1];
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]+1);
    return 0;
}