#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,b[5001];
struct node
{
	int sum,id,color;
}a[5001];
bool cmp1(node a,node b)
{
	return a.sum<b.sum;
}
bool cmp2(node a,node b)
{
	return a.id<b.id;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		a[i].id=i;
	}
	if(n<k)
	{
		printf("NO");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].sum);
		b[a[i].sum]++;
		if(b[a[i].sum]>k)
		{
			printf("NO");
			return 0;
		}
	}
	sort(a+1,a+n+1,cmp1);
	int now=1;
	for(int i=1;i<=n;i++)
	{
		a[i].color=now++;
		if(now==k+1)
		{
			now=1;
		}
	}
	sort(a+1,a+n+1,cmp2);
	printf("YES\n");
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i].color);
	}
	return 0;
}
//ff