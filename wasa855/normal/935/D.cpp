#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
#define mod 1000000007
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
int inv(int x)
{
	return qpow(x,mod-2);
}
#define N 100005
int a[N],b[N];
signed main()
{
	int n,m;
	cin>>n>>m;
//	cout<<(16*inv(26)%mod)<<endl;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=read();
	}
	int ans=0,tmp=1;
	int xi=inv(m);
	int xii=xi*xi%mod;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=0&&b[i]!=0)
		{
			if(a[i]<b[i])
			{
				tmp=0;
			}
			else if(a[i]>b[i])
			{
				ans=(ans+tmp)%mod;
				tmp=0;
			}
			else
			{
				continue;
			}
		}
		else if(a[i]==0&&b[i]!=0)
		{
			ans=(ans+tmp*(m-b[i])%mod*xi%mod)%mod;
			tmp=tmp*xi%mod;
		}
		else if(a[i]!=0&&b[i]==0)
		{
			ans=(ans+tmp*(a[i]-1)%mod*xi%mod)%mod;
			tmp=tmp*xi%mod;
		}
		else
		{
			int sum=m*(m-1)/2;
			ans=(ans+tmp*sum%mod*xii%mod)%mod;
			tmp=tmp*xi%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}