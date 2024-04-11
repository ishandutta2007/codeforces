#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
ll sum(ll n)
{
	n%=MOD;
	return n*(n+1)/2%MOD;
}
ll calc(ll n)
{
	ll nxt[2]={0,0};
	int now=0;
	ll num=0,k=1;
	while(num<n)
	{
		now^=1;
		if(num+k<=n)nxt[now]+=k,num+=k;
		else nxt[now]+=n-num,num=n;
		k<<=1;
	}
	return 2*sum(nxt[0])+2*sum(nxt[1])-nxt[1];
}
int main()
{
	ll l,r;
	scanf("%I64d%I64d",&l,&r);
	ll ans=(calc(r)-calc(l-1))%MOD;
	if(ans<0)ans+=MOD;
	printf("%I64d\n",ans);
	return 0;
}