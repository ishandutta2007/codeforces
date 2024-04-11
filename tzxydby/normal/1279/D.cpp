#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000005,mod=998244353;
int a[N],b[N],n,ans,sum;
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	int inv1=qp(n,mod-2);
	for(int i=1;i<=n;i++)
	{
		int m,x;
		cin>>m;
		sum+=m;
		int invm=qp(m,mod-2);
		while(m--)
		{
			cin>>x;
			a[x]++;
			b[x]=(b[x]+inv1*invm%mod)%mod;
		}
	}
	for(int i=1;i<=1000000;i++)
		if(a[i])
			ans=(ans+b[i]*a[i]%mod*inv1%mod)%mod;
	cout<<ans<<endl;
	return 0;
}