#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define cs const
#define il __inline__ __attribute__((always_inline))
#define mod 998244353
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 100000
vector<int>sn[max_n+1];
int deg[max_n+1],que[max_n+1],par[max_n+1],ans[max_n],cnt[max_n+1];
int check(ci n,ci k){
	memset(cnt+1,0,n<<2);
	for(int i=1; i<n; ++i){
		int u=que[i];
		if(cnt[u]%k){
			if((++cnt[u])%k)
				return 0;
		}
		else
			++cnt[par[u]];
	}
	return 1;
}
il void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		sn[i].clear();
	memset(deg+1,0,n<<2);
	for(int i=n,u,v; --i; ){
		scanf("%d%d",&u,&v);
		sn[u].push_back(v),
		sn[v].push_back(u),
		++deg[u],++deg[v];
	}
	int tail=0;
	for(int i=1; i<=n; ++i)
		if(deg[i]==1)
			que[++tail]=i;
	for(int head=1; head<n; ++head){
		int u=que[head];
		for(auto v:sn[u])
			if(deg[v]>1){
				par[u]=v;
				if(--deg[v]==1)
					que[++tail]=v;
			}
	}
	int m=n-1;
	ans[1]=1;
	for(int i=m; i; --i,ans[1]=(ans[1]<<1)%mod);
	for(int i=m; i>1; --i)
		if(!(m%i)){
			ans[i]=check(n,i);
			for(int j=i<<1; j<=m; j+=i)
				ans[i]-=ans[j];
			ans[1]-=ans[i];
		}
		else
			ans[i]=0;
	for(int i=1; i<n; ++i)
		printf("%d ",ans[i]);
	puts("0");
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}