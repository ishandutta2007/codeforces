#include<bits/stdc++.h>
using namespace std;
#define ls(x) t[x].ch[0]
#define rs(x) t[x].ch[1]
const int N = 5e4+9;
int n,m,a[N],head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;}
int dep[N],f[N][256],p[N],pa[N];

int rt,cnt;
struct Tire{int ch[2];}t[N];

void insert(int x){
    int p=rt;
    for(int i=15;i>=0;i--){
        if(!t[p].ch[((x>>i)&1)]) t[p].ch[((x>>i)&1)]=++cnt;
        p=t[p].ch[((x>>i)&1)];
    }
    return ;
}
void clear(){
    for(int i=1;i<=cnt;i++) ls(i)=0,rs(i)=0;
    rt=1,cnt=1;return ;
}
int query(int x){
    int p=rt,ans=0;
    for(int i=15;i>=0;i--){
        int k=(x>>i)&1;
        if(t[p].ch[!k]) p=t[p].ch[!k],ans|=(1<<i);
        else p=t[p].ch[k];
    }
    return ans;
}

int up(int u,int x,int h){
    h--;
    if(h==-1||!x) return x;
    insert(a[x]^(dep[u]-dep[x]));
    return up(u,pa[x],h);
}

void dfs(int u,int fa){
    dep[u]=dep[fa]+1,pa[u]=fa;
    clear();
    p[u]=up(u,u,256);
    for(int i=0;i<256;i++) f[u][i]=query((i<<8));
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;dfs(v,u);
    }
    return ;
}

int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d%d",&n,&m);rt=1;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
    }
    dfs(1,0);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        int ans=0,t=0,x=v;
        while(dep[p[x]]>=dep[u]){
            ans=max(ans,f[x][t]);
            x=p[x],t++;
        }
        while(dep[x]>=dep[u]){
            ans=max(ans,(a[x]^(dep[v]-dep[x])));
            x=pa[x];
        }
        printf("%d\n",ans);
    }
    return 0;
}