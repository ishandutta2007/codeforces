#include <cstdio>
#include <iostream>

using namespace std;

long long i,t,n,k,a[40],b[40];

int main()
{
	cin>>t;
	
	a[1]=4;
	b[1]=2;
	
	for (i=2;i<=32;++i)
	{
		a[i]=a[i-1]*4;
		b[i]=b[i-1]*2;
		a[i-1]=(a[i-1]-1)/3;
		b[i-1]+=b[i-2]-1;
	}
	
	while (t--)
	{
		cin>>n>>k;
		if (n>31)
		{
			cout<<"YES "<<n-1<<endl;
		}
		else if (k>a[n]||n==2&&k==3)
		{
			puts("NO");
		}
		else
		{
			for (i=1;i<=n;++i)
			{
				if (k>=b[i]&&k<=a[i]+a[n-i]*((1<<i)-1)*((1<<i)-1))
				{
					break;
				}
			}
			cout<<"YES "<<n-i<<endl;
		}
	}
	
	return 0;
}