#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x;
	int y;
	int n;
};
node a[300005];
bool cmp(node x,node y)
{
	if(x.x>y.x)
	{
		return true;
	}
	if(x.x<y.x)
	{
		return false;
	}
	return x.y<y.y;
}
int main()
{
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
		a[i].n=i;
	}
	sort(a+1,a+m+1,cmp);
//	for(int i=1;i<=m;i++)
//	{
//		printf("%d %d %d\n",a[i].x,a[i].y,a[i].n);
//	}
	for(int i=1;i<=m;i++)
	{
		if(a[i].y<=a[i+1].y)
		{
			printf("%d %d",a[i].n,a[i+1].n);
			return 0;
		}
	}
	cout<<"-1 -1";
	return 0;
}