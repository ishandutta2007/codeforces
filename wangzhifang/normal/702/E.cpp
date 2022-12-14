#include <cstdio>
#include <cstring>
#include <list>
#define max_n 100000
#define max_logn 17
#define INF 2147483647
using namespace std;
template<typename T,typename Tv>void minify(T&x,Tv&y){
	y<x&&(x=y);
}
int mca/*mincyc_alloc*/[max_n<<1],acc/*alloc_cnt*/,
	minp[max_n+1][max_logn+1],par[max_n+1][max_logn+1];//multiplication
long long sca/*sumcyc_alloc*/[max_n<<1],
	sump[max_n+1][max_logn+1];//multiplication
int v[max_n+1],w[max_n+1],rt[max_n+1],dep[max_n+1],lgd[max_n+1],mink[max_n+1],*mincyc[max_n+1],cyclen[max_n+1];
long long sumk[max_n+1],*sumcyc[max_n+1];
list<int> f[max_n+1];
int stk[max_n+1],top;
int vis[max_n+1];
int solvert(int u,long long k){
	if(vis[u]){
		if(rt[u])
			return rt[u];
		int st=vis[u]-1,len=cyclen[u]=top-st,*stu=stk+st,*mcu=mincyc[u]=mca+acc;
		long long*scu=sumcyc[u]=sca+acc;
		acc+=len+1,scu[0]=0,mcu[0]=INF,sumk[u]=0,mink[u]=INF;
		for(int i=0; ++i<=len; scu[i]=scu[i-1]+w[stu[i]],mcu[i]=min(mcu[i-1],w[stu[i]]));
		dep[u]=0,lgd[u]=-1;
		return rt[u]=u;
	}
	stk[vis[u]=++top]=u;
	rt[u]=solvert(v[u],k);
	if(rt[u]!=u){
		dep[u]=dep[v[u]]+1;
		int siz=lgd[u]=lgd[v[u]]+bool((dep[u]&(dep[u]-1))==0&&dep[u]<=k),*mnp=minp[u],*pru=par[u],&mnk=mink[u];
		long long *smp=sump[u],&smk=sumk[u];
		smp[0]=mnp[0]=w[u],pru[0]=v[u],smk=0,mnk=INF;
		for(int i=0; ++i<=siz; smp[i]=smp[i-1]+sump[pru[i-1]][i-1],mnp[i]=min(mnp[i-1],minp[pru[i-1]][i-1]),pru[i]=par[pru[i-1]][i-1]);
		k>dep[u]&&(k=dep[u]);
		for(int i=lgd[u],now=u; k; i=31-__builtin_clz((now=par[now][i],k^=1<<i)))
			smk+=sump[now][i],minify(mnk,minp[now][i]);
	}
	--top;
	return rt[u];
}
void answering(int u,long long k,long long&ans1,int&ans2){
	ans1=sumk[u],ans2=mink[u];
	if(k<=dep[u])
		return;
	k-=dep[u];
	u=rt[u];
	ans1+=sumcyc[u][cyclen[u]]*(k/cyclen[u])+sumcyc[u][k%cyclen[u]],
	minify(ans2,k>=cyclen[u]?mincyc[u][cyclen[u]]:mincyc[u][k]);
}
int main(){
	int n,ans2;
	long long k,ans1;
	scanf("%d%lld",&n,&k),top=0,acc=0;
	memset(vis,0,sizeof(vis));
	memset(rt,0,sizeof(rt));
	for(int i=0; ++i<=n; f[i].clear());
	for(int i=0; ++i<=n; f[++v[i]].push_back(i))
		scanf("%d",v+i);
	for(int i=0; ++i<=n; scanf("%d",w+i));
	for(int i=0; ++i<=n; !rt[i]&&solvert(i,k));
	for(int i=0; ++i<=n; printf("%lld %d\n",ans1,ans2))
		answering(i,k,ans1,ans2);
	return 0;
}
/*
input:
4 10
2 3 2 0
1 1 1 1
output:
10 1
10 1
10 1
10 1
*/