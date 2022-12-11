#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int mod=998244353;
constexpr int max_n=200000,max_m=200000,max_v=200000;
ll quickpow(ll x,int k,ll ret=1){
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
int s[max_n+1],t[max_m+1];
int iv[max_n+1];
int tr[max_v+1],cnt[max_v+1];
int query(int p){
	int ret=0;
	for(; p; p&=p-1)
		ret+=tr[p]/*,printf("%d: %d\n",p,tr[p])*/;
	return ret;
}
void update(int p,const int v){
	for(; p<=max_v; p+=p&(-p))
		tr[p]+=v;
}
void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d",s+i);
	for(int i=1; i<=m; ++i)
		scanf("%d",t+i);
	ll now=1;
	for(int i=1; i<=n; ++i)
		now=now*i%mod;
	iv[n]=now=quickpow(now,mod-2);
	for(int i=n; i; --i)
		iv[i-1]=now=now*i%mod;
	for(int i=1; i<n; ++i)
		iv[i+1]=iv[i+1]*(now=now*i%mod)%mod;
	now=1;
	memset(tr,0,sizeof(tr)),memset(cnt,0,sizeof(cnt));
	for(int i=1; i<=n; ++i){
		++tr[s[i]],++cnt[s[i]];
		now=now*i%mod*iv[tr[s[i]]]%mod;
	}
//	for(int i=1; i<=n; ++i)
//		printf("*%d: %d\n",i,tr[i]);
	for(int i=2; i<=max_v; i<<=1)
		for(int j=i,d=i>>1; j<=max_v; j+=i)
			tr[j]+=tr[j-d];
//	for(int i=1; i<=n; ++i)
//		printf("*%d: %d\n",i,tr[i]);
	int ans=0;
//	printf("%lld\n",now);
	for(int i=0; i<m; ++i){
		const int x=query(t[i+1]-1);
		now=now*iv[n-i]%mod;
//		printf("%lld %d\n",now,x);
		ans=(ans+x*now)%mod;
		if(i==n)
			(++ans)==mod&&(ans=0);
		if(!cnt[t[i+1]])
			break;
//		printf("%d\n",cnt[t[i+1]]);
		now=now*cnt[t[i+1]]%mod;
		--cnt[t[i+1]];
		update(t[i+1],-1);
	}
	printf("%d\n",ans);
//	printf("%lld\n",now);
}
int main(){
	test();
//	int t;
//	scanf("%d",&t);
//	for(; t; test(),--t);
	return 0;
}