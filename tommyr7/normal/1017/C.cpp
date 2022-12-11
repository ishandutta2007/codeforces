#include <bits/stdc++.h>
using namespace std;
int n,t;
int ans[200007];
int main()
{
	scanf("%d",&n);
	t=(int)sqrt(n);
	int now=0;
	for (int i=1;i<=(n+t-1)/t;i++)
	{
		int p=i*t;
		if (p>n) p=n;
		for (int j=1;j<=t;j++)
			ans[(i-1)*t+j]=p--;
	}
	for (int i=n;i;i--)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}