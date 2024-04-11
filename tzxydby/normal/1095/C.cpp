#include<bits/stdc++.h>
using namespace std;
int a[31];
int main()
{
	int n,k,sum=0;
	scanf("%d%d",&n,&k);
	for(int i=30,x=n;x;i--)
	{
		if((1<<i)<=x)
		{
			x-=(1<<i);
			a[i]++;
			sum++;
		}
	}
	if(n<k||sum>k)
	{
		puts("NO");
		return 0;
	}
	sum++;
	for(int i=30;sum<=k;i--)
	{
		while(a[i]&&sum<=k)
		{
			a[i]--;
			sum++;
			a[i-1]+=2;
		}	
	}
	puts("YES");
	for(int i=0;i<=30;i++)
		for(int j=1;j<=a[i];j++)
			printf("%d ",1<<i);
	puts("");
	return 0;
}