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
int T,n; 
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<int> Ans;
		Ans.clear();
		Ans.push_back(0);
		for(int i=1;i<=n;++i)
		{
			Ans.push_back(n/i);
			i=n/(n/i);
		}
		sort(Ans.begin(),Ans.end());
		int k=Ans.size();
		printf("%d\n",k);
		for(int i=0;i<Ans.size();++i)printf("%d%c",Ans[i],(i==k-1)?'\n':' ');
	}
}