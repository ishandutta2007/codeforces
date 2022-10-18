#include<bits/stdc++.h>
using namespace std;
int a[1005];
int m,n;
void print()
{
	for(int i=1;i<=m;i++)
	{
		printf("%d ",a[i]);
	}
	cout<<'\n';
}
bool judge()
{
	for(int i=1;i<=m;i++)
	{
		if(a[i]==0)
		{
			return false;
		}
	}
	return true;
}
void erase()
{
	for(int i=1;i<=m;i++)
	{
		a[i]--;
	}
}
int main()
{
	int ans=0;
	cin>>m>>n;
	int t;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		a[t]++;
//		print();
		if(judge()==true)
		{
			ans++;
			erase();
		}
	}
	cout<<ans<<endl;
	return 0;
}