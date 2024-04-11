#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int n,a[200001];
map<int,int>r;
void checkmax(int &x,int y)
{
	if(x<y)
	{
		x=y;
	}
}
long long ksm(long long a,long long b,long long mod)
{
	long long s=1;
	while(b)
	{
		if(b&1)
		{
			s=s*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return s;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--)
	{
		if(r[a[i]]!=0)
		{
			continue;
		}
		r[a[i]]=i;
	}
	int temp=1,last=1,ans=0;
	while(temp<=n)
	{
		for(;temp<=last&&temp<=n;temp++)
		{
			checkmax(last,r[a[temp]]);
			//cout<<"temp:"<<temp<<' '<<"last:"<<last<<endl; 
		}
		ans++;
		last++;
		if(last>n)
		{
			break;
		}
	}
	printf("%lld",(ksm(2,ans-1,998244353)+998244353)%998244353);
	return 0;
}