#include <bits/stdc++.h>
using namespace std;
const int maxn=110;
int a[maxn],ans=0,ans1=0;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			ans=0;
			for(int k=i;k<=j;k++)
			{
				if(a[k]==0)	ans++;
			}
			for(int k=n-1;k>j;k--)
			{
				if(a[k]==1)	ans++;
			}
			for(int l=0;l<i;l++)
			{
				if(a[l]==1)	ans++;
			}
			ans1=max(ans1,ans);
		}
	}
	cout<<ans1<<endl;
	return 0;
}