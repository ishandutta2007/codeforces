#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;
typedef long long ll;

ll m,d,w,t,n;
ll gcd(ll x,ll y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%lld%lld%lld",&m,&d,&w);
		n=min(m,d);
		ll g=gcd(d-1,w),tmp=w/g;
		if(tmp==1)
		{
			printf("%lld\n",n*(n-1)/2);
			continue;
		}
		ll rest=n%tmp,q=(n+tmp-1)/tmp-1; if(rest==0) rest=tmp;
		ll ans=(q+1)*q/2*rest;
		ans+=(q-1)*q/2*(tmp-rest);
		printf("%lld\n",ans);
	}
	return 0;
}