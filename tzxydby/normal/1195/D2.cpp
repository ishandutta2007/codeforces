#include<bits/stdc++.h>
using namespace std;
const int N=100005,mod=998244353;
long long a[N],p[25],d[25];
int main()
{
	p[0]=1;
	for(int i=1;i<=20;i++)
		p[i]=p[i-1]*10%mod;
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		long long dig=0,x=a[i];
		while(x)
		{
			x/=10;
			dig++;
		}
		d[dig]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int dig=1;dig<=10;dig++)
		{
			int j=1,k=1;
			long long x=a[i];
			while(x)
			{
				long long y=x%10;
				if(k<=dig)
				{
					long long add=y*(p[j]+p[j-1])*d[dig]%mod;
					ans=(ans+add)%mod;
					j+=2;
					k++;
				}
				else
				{
					long long add=y*p[k+dig-1]*2*d[dig]%mod;
					ans=(ans+add)%mod;
					j++;
					k++;
				}
				x/=10;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}