#include<bits/stdc++.h>
int main()
{
	int n,a[100],i;
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	if (a[n-1]==0)
	{
		printf("UP");
		return 0;
	}
	if (a[n-1]==15)
	{
		printf("DOWN");
		return 0;
	}
	if (n==1)
	{
		printf("-1");
		return 0;
	}
	if (a[n-1]>a[n-2])
		printf("UP");
	else
		printf("DOWN");
	return 0;
}