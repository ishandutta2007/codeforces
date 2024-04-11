#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005,mod=1e9+7;
int n,a[N],c[100],ans;
void sol()
{
	cin>>n;
	for(int i=0;i<60;i++)
		c[i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=0;j<60;j++)
			if(a[i]&(1LL<<j))
				c[j]++;
	}
	ans=0;
	for(int i=1;i<=n;i++)
	{
		int s1=0,s2=0;
		for(int j=0;j<60;j++)
		{
			int x=(1LL<<j)%mod;
			if(a[i]&(1LL<<j))
			{
				s1=(s1+x*c[j]%mod)%mod;
				s2=(s2+x*n%mod)%mod;
			}
			else
				s2=(s2+x*c[j]%mod)%mod;
		}
		ans=(ans+s1*s2%mod)%mod;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
		sol();
	return 0;
}