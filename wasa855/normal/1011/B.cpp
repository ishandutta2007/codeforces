#include<bits/stdc++.h>
using namespace std;
int a[105];
int sum[105];
int n,m;
bool cmp(int x)
{
	int tot=0;
	for(int i=1;i<=100;i++)
	{
		tot+=sum[i]/x;
	}
	return tot>=n;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		sum[a[i]]++;
	}
	int l=0;
	int r=105;
	int mid;
	while(l<r)
	{
		mid=(l+r+1)/2;
		if(cmp(mid)==true)
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<l<<endl;
	return 0;
}