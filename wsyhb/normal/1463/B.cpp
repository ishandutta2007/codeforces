#include<bits/stdc++.h>
using namespace std;
const int max_n=50+5;
int a[max_n],ans[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		long long sum1=0,sum2=0;
		for(int i=1;i<=n;++i)
		{
			if(i&1)
				sum1+=a[i]-1;
			else
				sum2+=a[i]-1;
		}
		if(sum1<sum2)
		{
			for(int i=1;i<=n;i+=2)
				a[i]=1;
		}
		else
		{
			for(int i=2;i<=n;i+=2)
				a[i]=1;
		}
		for(int i=1;i<=n;++i)
			printf("%d%c",a[i],i<n?' ':'\n');
	}
	return 0;
}