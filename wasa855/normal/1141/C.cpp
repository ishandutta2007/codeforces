#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool used[200005];
int n;
int judge(int x)
{
	memset(used,false,sizeof(used));
	used[x]=true;
	for(int i=1;i<n;i++)
	{
		x+=a[i];
		if(x<1)
		{
			return 1;
		}
		if(x>n)
		{
			return 0;
		}
		if(used[x]==true)
		{
			cout<<"-1\n";
			exit(0);
		}
		used[x]=true;
	}
	return 2;
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int l=1,r=n,mid,ans=-1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		int ind=judge(mid);
		if(ind==1)
		{
			l=mid+1;
		}
		if(ind==0)
		{
			r=mid-1;
		}
		if(ind==2)
		{
			ans=mid;
			break;
		}
	}
	if(ans==-1)
	{
		cout<<"-1\n";
		return 0;
	}
	cout<<ans<<" ";
	for(int i=1;i<n;i++)
	{
		ans+=a[i];
		printf("%d ",ans);
	}
	return 0;
}