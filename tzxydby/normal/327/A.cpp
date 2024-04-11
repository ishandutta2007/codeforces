#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int main()
{
	int n,sum,sum1=0,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i])
			sum1++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			sum=0;
			for(int k=i;k<=j;k++)
			{
				if(a[k])
					sum--;
				else
					sum++;
			}
			ans=max(ans,sum1+sum);
		}
	}
	printf("%d\n",ans);
	return 0;
}