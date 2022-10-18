#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	int pl;
	bool operator < (const Node &x) const
	{
		return data<x.data;
	}
};
Node a[5005];
int ans[5005];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].data);
		a[i].pl=i;
	}
	sort(a+1,a+n+1);
	int sum=0;
	int col=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].data!=a[i-1].data)
		{
			sum=0;
		}
		sum++;
		if(sum>k)
		{
			cout<<"NO\n";
			return 0;
		}
		ans[a[i].pl]=col+1;
		col=(col+1)%k;
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
	cout<<"\n";
	return 0;
}