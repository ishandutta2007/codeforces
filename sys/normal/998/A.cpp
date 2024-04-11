#include <bits/stdc++.h>
using namespace std;
int n,total;
struct aa
{
	int id,w;
	bool operator < (const aa &b)const
	{
		return w<b.w;
	}
}a[15];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].w);
		total+=a[i].w;
		a[i].id=i;
	}
	if(n==2&&a[1].w==a[2].w){printf("-1");return 0;}
	if(n==1){printf("-1");return 0;}
	sort(a+1,a+1+n);
	printf("%d\n",n-1);
	for(int i=2;i<=n;i++)
		printf("%d ",a[i].id);
	return 0;
}