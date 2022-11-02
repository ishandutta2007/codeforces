#include<bits/stdc++.h>
using namespace std;
#define ls(x) t[x].ch[0]
#define rs(x) t[x].ch[1] 
const int N = 1e5+9;
int n,m,head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;}
int siz[N],in[N],vis[N],num,dfn[N],dep[N],f[N][22];
void dfs(int u,int fa){
    in[u]=++num,dfn[num]=u,siz[u]=1,dep[u]=dep[fa]+1,f[u][0]=fa;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;dfs(v,u);siz[u]+=siz[v];
    }
}
int rt[N],cnt;
struct treap{int ch[3],val,siz,rnd;}t[N];
int New(int x){t[++cnt].siz=1,t[cnt].val=x,t[cnt].rnd=rand();return cnt;}
void update(int c){t[c].siz=t[ls(c)].siz+t[rs(c)].siz+1;}
void split(int c,int k,int &x,int &y){
    if(!c) x=0,y=0;
    else{
        if(t[c].val<=k) x=c,split(rs(c),k,t[c].ch[1],y);
        else y=c,split(ls(c),k,x,t[c].ch[0]);
        update(c);
    }
}
int merge(int x,int y){
    if(!x||!y) return x+y;
    if(t[x].rnd<t[y].rnd){
        t[x].ch[1]=merge(t[x].ch[1],y);
        update(x);return x;
    }
    else{
        t[y].ch[0]=merge(x,t[y].ch[0]);
        update(y);return y;
    }
}
int main(){
    srand(19262337);
    memset(rt,0,sizeof(rt));
    memset(vis,0,sizeof(vis));
    memset(siz,0,sizeof(siz));
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){int x;scanf("%d",&x);if(x) add(x,i);else vis[i]=1;}
    for(int i=1;i<=n;i++) if(vis[i]) dfs(i,0);
    for(int j=1;j<=21;j++)
        for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
    cnt=0;
    for(int i=1;i<=n;i++){
        rt[dep[dfn[i]]]=merge(rt[dep[dfn[i]]],New(i));
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int c,k,d;scanf("%d%d",&c,&k);d=dep[c];
        for(int j=21;j>=0;j--) if(k>=(1<<j)) c=f[c][j],k-=(1<<j);
        if(!c){printf("0 ");continue;}
        int l=in[c],r=in[c]+siz[c]-1,x,y,z;
        split(rt[d],r,x,y);
        split(x,l-1,x,z);
        printf("%d ",t[z].siz-1);rt[d]=merge(merge(x,z),y);
    }
    puts("");
    return 0;
}