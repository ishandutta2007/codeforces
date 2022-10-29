#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 300010;

int a[N],xsum[N>>1],cnt[1<<20],n;

LL calc(int mod2){
	memset(xsum,0,sizeof xsum);
	memset(cnt,0,sizeof cnt);
	if(!mod2){
		cnt[0]=1;
		rep(i,1,n/2)xsum[i]=xsum[i-1]^a[i*2-1]^a[i*2],++cnt[xsum[i]];
	}else{
		xsum[0]=a[1];cnt[a[1]]=1;
		rep(i,1,(n-1)/2)xsum[i]=xsum[i-1]^a[i*2]^a[i*2+1],++cnt[xsum[i]];
	}
	LL ans=0;
	rep(i,0,(1<<20)-1)ans+=1ll*cnt[i]*(cnt[i]-1)/2;
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",a+i);
	printf("%lld\n",calc(0)+calc(1));
	return 0;
}