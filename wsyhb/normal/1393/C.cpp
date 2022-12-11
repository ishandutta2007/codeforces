#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int N=1e5+5;
int cnt[N],ans[N],sum1[N],sum2[N];
bool cmp(int x,int y)
{
	return x>y;
}
int n;
bool check(int x)
{
	for(int i=1;i<=x;i++) ans[i]=(n+x-i)/x;
	for(int i=1;i<=n;i++)
	{
		sum1[i]=sum1[i-1]+cnt[i];
		sum2[i]=sum2[i-1]+ans[i];
		if(sum1[i]>sum2[i]) return false;
	}
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			cnt[x]++;
		}
		sort(cnt+1,cnt+n+1,cmp);
		int l=1,r=n-1,mid,ans;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid)) ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans-1);
		for(int i=1;i<=n;i++) cnt[i]=0;
	}
	return 0;
}