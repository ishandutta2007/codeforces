#include<bits/stdc++.h>
using namespace std;
int a[20],t[20],n;
int check()
{
	int sum=0;
	for(int i=1;i<=n;i++)
		if(t[i])
			sum+=a[i];
		else
			sum-=a[i];
	sum=abs(sum);
	if(sum%360==0)
		return 1;
	else
		return 0;
}
void dfs(int x)
{
	if(x==n+1)
	{
		if(check())
		{
			puts("YES");
			exit(0);
		}
		return;
	}
	t[x]=1;
	dfs(x+1);
	t[x]=0;
	dfs(x+1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	puts("NO"); 
	return 0;
}