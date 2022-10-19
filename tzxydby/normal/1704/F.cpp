#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,a[N],c[2],dp[N],b[N];
char s[N];
int dfs(int x)
{
	if(x==2||x==3) return dp[x]=1;
	if(x==0||x==1) return dp[x]=0;
	if(dp[x]!=-1) return dp[x];
	for(int i=0;i<=200;i++)
		b[i]=0;
	for(int i=0;i<x-1;i++)
		b[dfs(x-i-2)^dfs(i)]=1;
	for(int i=0;;i++)
	{
		if(!b[i])
		{
			dp[x]=i;
			break;
		}
	}
	return dp[x];
}
int cal(int v){return (v<=120?dp[v]:dp[v%34+68]);}
void sol()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		a[i]=(s[i]=='B');
	c[0]=c[1]=0;
	for(int i=1;i<=n;i++)
		c[a[i]]++;
	if(c[0]!=c[1])
	{
		if(c[0]>c[1])
			puts("Alice");
		else
			puts("Bob");
	}
	else
	{
		int s=0,z=1;
		for(int i=2;i<=n+1;i++)
		{
			if(a[i]==a[i-1]||i>n)
			{
				s^=cal(z);
				z=1;
			}
			else
				z++;
		}
		puts(s?"Alice":"Bob");
	}
}
int main()
{
	for(int i=0;i<=200;i++)
		dp[i]=-1;
	for(int i=0;i<=120;i++)
		dp[i]=dfs(i);
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}