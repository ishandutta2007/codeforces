#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	int ans=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int tmp=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			tmp++;
		}
		else
		{
			tmp=0;
		}
		if(tmp>ans)
		{
			ans=tmp;
		}
	}
	int l=0;
	while(a[l+1]==1)
	{
		l++;
	}
	int r=n+1;
	while(a[r-1]==1)
	{
		r--;
	}
	tmp=l+(n-r+1);
	if(tmp>ans)
	{
		ans=tmp;
	}
	cout<<ans<<endl;
	return 0;
}