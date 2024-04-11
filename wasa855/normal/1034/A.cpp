#include<bits/stdc++.h>
using namespace std;
bool su[15000005];
int maxn=0;
int a[300005];
int s[15000005];
void prime()
{
	for(int i=2;i<=maxn;i++)
	{
		if(su[i]==false)
		{
			for(int j=i+i;j<=maxn;j+=i)
			{
				if(su[j]==false)
				{
					break;
				}
				su[j]=true;
			}
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int gcd;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(maxn<a[i])
		{
			maxn=a[i];
		}
		if(i==1)
		{
			gcd=a[i];
		}
		else
		{
			gcd=__gcd(gcd,a[i]);
		}
	}
	if(gcd==maxn)
	{
		cout<<"-1\n";
		return 0;
	}
//	prime();
	for(int i=1;i<=n;i++)
	{
		a[i]/=gcd;
		s[a[i]]++;
	}
	int ans=0;
	for(int i=2;i<=maxn;i++)
	{
		if(su[i]==false)
		{
			int sum=0;
			for(int j=i;j<=maxn;j+=i)
			{
				sum+=s[j];
				su[j]=true;
			}
			if(sum>ans)
			{
				ans=sum;
			}
		}
	}
	cout<<n-ans<<endl;
	return 0;
}