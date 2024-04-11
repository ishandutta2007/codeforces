#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int n,m[17],r[17];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&r[i]);
	}
	int sum=0;
	for(int i=1;i<=1000000;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i%m[j]==r[j])
			{
				sum++;
				break;
			}
		}
	}
	printf("%.6lf",sum/1000000.0);
	return 0;
}