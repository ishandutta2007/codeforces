#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long long n;
	cin>>n;
	if(n==1)
	{
		printf("1\n0\n");
		return 0;
	}
	long long p1=-1,p2=-1;
	for(long long i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			p1=i;
			n/=i;
			break;
		}
	}
	if(p1==-1)
	{
		printf("1\n0\n");
		return 0;
	}
	for(long long i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			p2=i;
			n/=i;
			break;
		}
	}
	if(p2==-1)
	{
		printf("2\n");
		return 0;
	}
	printf("1\n%lld\n",p1*p2);
	return 0;
}