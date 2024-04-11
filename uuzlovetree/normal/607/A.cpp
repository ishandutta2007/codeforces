#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n;
struct node
{
	int x,y;
}a[maxn];
bool operator < (node a,node b)
{
	return a.x<b.x;
}
int dp[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		int l=0,r=i-1,ans=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[mid].x<a[i].x-a[i].y)ans=mid,l=mid+1;
			else r=mid-1; 
		}
		dp[i]=dp[ans]+1;
	}
	int res=0;
	for(int i=1;i<=n;++i)res=max(res,dp[i]);
	printf("%d\n",n-res);
	return 0;
}