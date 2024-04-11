#include<bits/stdc++.h>
using namespace std;
int a[1100000];
void init()
{
	for(int i=0;i<=210000;i++)
	{
		if(i<=9) a[i]=1;
		else
		{
			a[i]=(a[i-9]+a[i-10])%1000000007;
		}
	}
}
int main()
{
	init();
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int ans=0;
		for(;n>0;n/=10)
		{
			ans+=a[m+n%10];
			ans%=1000000007;
		}
		printf("%d",ans);
		if(i<t) printf("\n");
	}
	return 0;
}