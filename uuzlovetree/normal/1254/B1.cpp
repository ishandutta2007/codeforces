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
#define maxn 1000005 
int n,tot;
int a[maxn];
ll ans;
void check(int k)
{
	ll res=0;
	vector<int> v;
	for(int i=1;i<=n;++i)
	{
		v.clear();
		ll sx=0,sy=0;
		while(i<=n&&v.size()<k)
		{
			if(a[i]==1)v.push_back(i),sy+=i;
			if(v.size()==k)break;
			++i;
		}
		ll t=(ll)1e15;
		if(v.size()>0)
		{
			for(int p=0;p<k;++p)
			{
				t=min(t,1ll*p*v[p]-sx+sy-1ll*(k-p)*v[p]);
				sx+=v[p];sy-=v[p];
			}
			res+=t;
		}
	}
	ans=min(ans,res);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),tot+=a[i];
	if(tot==1)
	{
		puts("-1");
		return 0;
	}
	ans=(ll)1e15;
	for(int i=1;i*i<=tot;++i)if(tot%i==0)
	{
		if(i!=1)check(i);
		if(i*i!=tot)check(tot/i);
	}
	cout<<ans<<endl;
}