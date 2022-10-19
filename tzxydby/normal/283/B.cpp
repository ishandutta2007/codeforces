#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],vis[2][N];
long long dp[2][N];
long long go(int s,int x)
{
	if(x<=0||x>n)
		return 0;
	if(x==1||vis[s][x]==1)
		return -1;
	long long &ret=dp[s][x];
	if(vis[s][x]==2)
		return ret;
	vis[s][x]=1;
	long long val=go(s^1,(s==0?x+a[x]:x-a[x]));
	vis[s][x]=2;
	if(val==-1)
		return ret=-1;
	else
		return ret=a[x]+val;
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<n;i++)
	{
		long long val=go(1,1+i);
		if(val==-1)
			printf("-1\n");
		else
			printf("%I64d\n",val+i);
	}
	return 0;
}