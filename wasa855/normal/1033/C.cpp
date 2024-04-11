#include<bits/stdc++.h>
using namespace std;
int a[100005];
int ans[100005];
int main()
{
	int n;
	cin>>n;
	int u;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&u);
		a[u]=i;
	}
	ans[a[n]]=2;
	for(int i=n-1;i>0;i--)
	{
		bool ok=false;
		for(int j=a[i]+i;j<=n;j+=i)
		{
			if(ans[j]==2)
			{
				ok=true;
			}
		}
		for(int j=a[i]-i;j>0;j-=i)
		{
			if(ans[j]==2)
			{
				ok=true;
			}
		}
		if(ok==true)
		{
			ans[a[i]]=1;
		}
		else
		{
			ans[a[i]]=2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i]==1)
		{
			cout<<"A";
		}
		else
		{
			cout<<"B";
		}
	}
	cout<<"\n";
	return 0;
}