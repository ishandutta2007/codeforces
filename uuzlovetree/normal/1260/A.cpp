#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define mpr(a,b) make_pair(a,b)
using namespace std;
ll gcd(ll a,ll b){if(!b)return a;return gcd(b,a%b);}
ll fastpow(ll a,ll p,ll mod)
{
	ll ans=1;
	while(p)
	{
		if(p&1)ans=ans*a%mod;
		a=a*a%mod;p>>=1;
	}
	return ans;
}
ll inv(ll x,ll mod){return fastpow(x,mod-2,mod);}
int T;
int c,sum;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&c,&sum);
		int t=sum/c;
		int A=sum-c*t;
		int B=c-A;
		ll ans=1ll*A*(t+1)*(t+1)+1ll*B*t*t;
		cout<<ans<<endl;
	}
}