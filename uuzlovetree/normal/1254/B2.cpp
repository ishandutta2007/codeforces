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
int n;
ll tot,a[maxn],ans;
ll b[maxn],c[maxn];
void check(ll k)
{
	ll res=0,tt=0;
	vector<pll> v;
	for(int i=1;i<=n;++i)b[i]=a[i]%k,tt+=b[i],c[i]=b[i];
	ll K=tt/k;
	int j=1;
	for(int i=1;i<=K;++i)
	{
		v.clear();
		ll sx=0,sy=0,num=0;
		while(j<=n&&num<=k)
		{
			if(b[j]>0)
			{
				ll tmp=min(b[j],k-num);
				v.push_back(mpr(j,tmp)),sy+=j*tmp,num+=tmp;
				b[j]-=tmp;
			}
			if(num==k)break;
			j++;
		}
		ll t=(ll)5e18;
		if(v.size())
		{
			ll s=0;
			for(int p=0;p<v.size();++p)
			{
				ll pos=v[p].first;
				t=min(t,1ll*pos*s-sx+sy-1ll*(k-s)*pos);
				sx+=pos*v[p].second;sy-=pos*v[p].second;
				s+=v[p].second;
			}
			res+=t;
		}
	}
	ans=min(ans,res);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%I64d",&a[i]),tot+=a[i];
	if(tot==1)
	{
		puts("-1");
		return 0;
	}
	ans=(ll)5e18;
	ll x=tot;
	for(ll i=2;i*i<=tot;++i)if(x%i==0)
	{
		while(x%i==0)x/=i;
		check(i);
	}
	if(x>1)check(x);
	cout<<ans<<endl;
}