#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int a[2000005],b[2000005],dp[2000005],n,k;
const int inf=2e12,qwqinf=1e10;
inline void ins(int x)
{
	int l=0,r=n,qwq=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(dp[mid]<=x) qwq=mid,l=mid+1;
		else r=mid-1;
	}
	dp[qwq+1]=min(dp[qwq+1],x);
}
inline int cal(int l1,int r1,int l2,int r2)
{
	int rtn=0,mx=0;
	dp[0]=-inf;
	for(int i=l1;i<=r1;i++)
	{
		if(a[i]<l2+i-l1||a[i]>r2-r1+i) continue;
		ins(a[i]+qwqinf-i);
	}
	for(int i=1;i<=r1-l1+1;i++) if(dp[i]<inf/2) mx=i,dp[i]=inf;
	return r1-l1+1-mx;
}
signed main(int argc, char** argv) {
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),dp[i]=inf;
	a[0]=-inf,a[n+1]=inf;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&b[i]);
		if(a[b[i]]-a[b[i-1]]<b[i]-b[i-1])
		{
			puts("-1");
			return 0;
		}
	}
	b[k+1]=n+1;
	int ans=0;
	for(int i=1;i<=k+1;i++)
		ans+=cal(b[i-1]+1,b[i]-1,a[b[i-1]]+1,a[b[i]]-1);
	cout << ans;
	return 0;
}