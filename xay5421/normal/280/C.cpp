#include<cstdio>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N=100005;
int n,a[N],dep[N];double res;
struct ed{ed*nxt;int to;}pool[N<<1],*p=pool,*lnk[N];
void ae(int u,int v){*++p=(ed){lnk[u],v},lnk[u]=p;}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for(ed*i=lnk[u];i;i=i->nxt)if(i->to!=fa)dfs(i->to,u);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		int u,v;scanf("%d%d",&u,&v);
		ae(u,v),ae(v,u);
	}
	dfs(1,1);
	rep(i,1,n)res+=1.0/dep[i];
	printf("%.9lf\n",res);
	return 0;
}