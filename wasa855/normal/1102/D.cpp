#include<bits/stdc++.h>
using namespace std;
int a[300005];
bool defi[300005];
int sum[4];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%1d",&a[i]);
		sum[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(sum[a[i]]<n/3)
		{
			defi[i]=true;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(sum[a[i]]>n/3&&sum[0]<n/3&&a[i]!=0)
		{
			sum[a[i]]--;
			a[i]=0;
			sum[0]++;
			defi[i]=true;
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(sum[a[i]]>n/3&&sum[2]<n/3&&a[i]!=2)
		{
			sum[a[i]]--;
			a[i]=2;
			sum[2]++;
			defi[i]=true;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(defi[i]==false&&sum[a[i]]>n/3&&a[i]==2)
		{
			sum[a[i]]--;
			a[i]=1;
			sum[1]++;
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(defi[i]==false&&sum[a[i]]>n/3&&a[i]==0)
		{
			sum[a[i]]--;
			a[i]=1;
			sum[1]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d",a[i]);
	}
	cout<<"\n";
	return 0;
}