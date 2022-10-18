#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	int pl;
};
Node a[2005];
bool cmp(Node a,Node b)
{
	return a.data>b.data;
}
int ans[2005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].data);
		a[i].pl=i;
	}
	sort(a+1,a+n+1,cmp);
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		sum+=a[i].data;
		ans[i]=a[i].pl;
	}
	sort(ans+1,ans+m+1);
	int t=0;
	ans[m+1]=n;
	ans[0]=0;
	cout<<sum<<endl;
//	for(int i=1;i<=m;i++)
//	{
//		printf("%d ",ans[i]);
//	}
//	cout<<"\n";
	for(int i=1;i<m;i++)
	{
		printf("%d ",ans[i]-ans[i-1]);
	}
	cout<<n-ans[m-1];
	return 0;
}