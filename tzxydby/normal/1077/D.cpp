#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int vis[N],n,k;
int check(int len)
{
	int sum=0;
	for(int i=1;i<=200000;i++)
		sum+=vis[i]/len;
	if(sum>=k)
		return 1;
	else
		return 0;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		vis[x]++;
	}
	int lb=0,ub=n+1;
	while(ub-lb>1)
	{
		int mid=(lb+ub)>>1;
		if(check(mid))
			lb=mid;
		else
			ub=mid;
	}
	int ans=n/lb,sum=0;
	for(int i=1;sum<k;i++)
	{
		while(vis[i]>=lb&&sum<k)
		{
			printf("%d ",i);
			vis[i]-=lb;
			sum++;
		}
	}
	printf("\n");
	return 0;
}