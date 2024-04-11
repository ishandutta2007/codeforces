#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005,mod=1000000007;
int n,x,a[N],b[N],m,ans;
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
	for(int i=1;i<=n;i++)
		cin>>x,a[x]++;
	for(int i=1;i<=100000;i++)
		a[i]+=a[i-1];
	for(int i=1;a[i-1]<n;i++)
	{
		m=0;
		for(int j=1;j*j<=i;j++)
		{
			if(i%j==0)
			{
				b[m++]=j-1;
				if(j*j!=i)
					b[m++]=i/j-1;
			}
		}
		sort(b,b+m);
		int s=1;
		for(int i=1;i<m;i++)
			s=s*qp(i,a[b[i]]-a[b[i-1]])%mod;
		ans=(ans+s*(qp(m,n-a[b[m-1]])+mod-qp(m-1,n-a[b[m-1]])))%mod;
	}
	cout<<ans<<endl;
	return 0;
}