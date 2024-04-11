#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[200005];
bool judge(int x)
{
	int sum=0;
	int tmp=0;
	for(int i=x+1;i<=n;i++)
	{
		if(a[i]>k)
		{
			return false;
		}
		if(tmp+a[i]>k)
		{
			tmp=a[i];
			sum++;
		}
		else
		{
			tmp+=a[i];
		}
	}
	if(tmp!=0)
	{
		sum++;
	}
	return sum<=m;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int l=0,r=n,mid;
	int ans;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(judge(mid)==true)
		{
			r=mid-1;
			ans=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<n-ans<<endl;
	return 0;
}