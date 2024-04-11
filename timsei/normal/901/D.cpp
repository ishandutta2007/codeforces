#include <cstdio>
const int N=1e5+5;
const int M=N*5;
long long C[M],x,y,g[N],k[N];
int L[N],ne[M],T[M],ty=1,Q[N],J[N],n,m;
#define Fo(i,x) for(int i=L[x];i;i=ne[i])
#define F(i,b) for(int i=1;i<=b;++i)
void add(int x,int y){ne[++ty]=L[x];L[x]=ty;T[ty]=y;}void link(int x,int y){add(x,y);add(y,x);}bool v[N];int dfs(int x,int f){int res=0;Q[x]=f;k[x]=k[f]+1;v[x]=1;Fo(i,x){int V=T[i];if(v[V]){if(V!=f){if((k[V]+k[x])&1);else res=i;}continue;}int h;if(h=dfs(V,x))res=h;if(g[V]){g[x]-=g[V];C[i]+=g[V];C[i^1]+=g[V];g[V]=0;}J[V]=i;}return res;}void B(int x){while(Q[x]){g[Q[x]]-=g[x];C[J[x]]+=g[x];C[J[x]^1]+=g[x];g[x]=0;x=Q[x];}}int main(void){scanf("%d%d",&n,&m);F(i,n)scanf("%lld",&g[i]);F(i,m)scanf("%d%d",&x,&y),link(x,y);F(i,n)if(!v[i]){int h=dfs(i,0),a;if((g[i])&1||(!h&&g[i]))return puts("NO")*0;a=(k[T[h]]&1);C[h]=C[h^1]+=g[i]/2*(a?1:(-1));g[T[h^1]]=g[T[h]]=-g[i]/2*(a?1:(-1));B(T[h]);B(T[h^1]);}puts("YES");F(i,m)printf("%lld\n",C[i*2]);}