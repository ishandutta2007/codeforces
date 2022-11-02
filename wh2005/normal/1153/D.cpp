#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+9;
int n,m,a[N],head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){
    g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
int f[N][2];
int Min(int x,int y){return (!x)?y:(x<y?x:y);}

void dfs(int u){
    if(head[u]==-1){f[u][0]=0,f[u][1]=1;return ;}
    f[u][0]=0,f[u][1]=0;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;dfs(v);
        if(a[u]==0) f[u][0]=0,f[u][1]+=f[v][1];
        if(a[u]==1) f[u][0]+=f[v][0],f[u][1]=Min(f[u][1],f[v][1]);
    }
    return ;
}

int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=2;i<=n;i++){int x;scanf("%d",&x);add(x,i);}
    m=0;for(int i=1;i<=n;i++) if(head[i]==-1) m++;
    dfs(1);printf("%d\n",m-f[1][1]+1);
    return 0;
}