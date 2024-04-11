#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],b[N];
char c[N];
int main()
{
	int n;
	long long sum0=0,sum1=0,sum20=0,sum21=0,sum=0;
	scanf("%d",&n);
	scanf("%s",c+1);
	for(int i=1;i<=n;i++)
		a[i]=c[i]-'0';
	scanf("%s",c+1);
	for(int i=1;i<=n;i++)
		b[i]=c[i]-'0';
	for(int i=1;i<=n;i++)
	{
		if(a[i])
			sum1++;
		else
			sum0++;
		if(!b[i])
		{
			if(a[i])
				sum20++;
			else
				sum21++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i])
			continue;
		if(a[i])
			sum+=sum0;
		else
			sum+=sum1;
	}
	printf("%I64d\n",sum-sum20*sum21);
	return 0;
}