#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,q,s[100005],sum[100005];
int main()
{
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&s[i]);
	sort(s+1,s+n+1);
	for(int i=n;i>=2;i--)s[i]-=s[i-1];
	for(int i=1;i<n;i++)s[i]=s[i+1];
	s[n]=5e18;
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+s[i];
	scanf("%I64d",&q);
	while(q--)
	{
		ll x,y;
		scanf("%I64d%I64d",&x,&y);
		ll len=y-x+1;
		int l=1,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(s[mid]<=len)l=mid+1;
			else r=mid-1;
		}
		printf("%I64d ",sum[r]+(n-r)*len);
	}
	printf("\n");
	return 0;
}