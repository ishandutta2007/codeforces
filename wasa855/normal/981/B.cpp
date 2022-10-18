#include<bits/stdc++.h>
using namespace std;
struct node
{
	int num;
	int data;
};
node a[200005];
bool cmp(node a,node b)
{
	if(a.num<b.num)
	{
		return true;
	}
	if(a.num>b.num)
	{
		return false;
	}
	return a.data<b.data;
}
int main()
{
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&a[i].num,&a[i].data);
	}
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i+m].num,&a[i+m].data);
	}
	sort(a+1,a+m+n+1,cmp);
//	for(int i=1;i<=m+n;i++)
//	{
//		printf("%d %d\n",a[i].num,a[i].data);
//	}
	long long ans=0;
	for(int i=1;i<=m+n;i++)
	{
		if(a[i].num==a[i+1].num)
		{
			continue;
		}
		ans+=a[i].data;
	}
	cout<<ans<<endl;
	return 0;
}