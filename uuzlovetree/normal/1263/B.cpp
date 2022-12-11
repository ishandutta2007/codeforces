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
string s[11]; 
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;++i)cin>>s[i];
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			bool yes=0;
			for(int j=1;j<i;++j)if(s[i]==s[j])yes=1;
			if(!yes)continue; 
			string tmp=s[i];
			ans++;
			for(int k=0;k<=9;++k)
			{
				tmp[0]=k+'0';
				int tot=0;
				for(int j=1;j<=n;++j)if(j!=i)if(tmp==s[j])tot++;
				if(!tot)break;
			}
			s[i]=tmp;
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;++i)cout<<s[i]<<endl;
	}
}