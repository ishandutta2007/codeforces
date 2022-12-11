#include <bits/stdc++.h>
#define Maxn 100007
using namespace std;
int n,A,X,Y,anss1,anss2;
long long m,ans=0,r;
int a[Maxn];
pair<int,int> s[Maxn];
long long sum1[Maxn],sum2[Maxn];
long long q[Maxn];
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return a.first>b.first;
}
bool check(long long k,int t)
{
	int lx=t+1,rx=n;
	while (rx-lx>1)
	{
		int mid=(lx+rx)/2;
		if (a[mid]<=k) rx=mid; else lx=mid;
	}
	int pos;
	if (a[lx]<=k) pos=lx; else pos=rx;
	if (1LL*k*(n-pos+1)-sum2[pos]<=r) return true;
	return false;
}
int main()
{
	scanf("%d%d%d%d%lld",&n,&A,&X,&Y,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i].first=a[i];
		s[i].second=i;
	}
	sort(s+1,s+n+1,cmp);
	memset(sum1,0,sizeof(sum1));
	memset(sum2,0,sizeof(sum2));
	for (int i=1;i<=n;i++)
		a[i]=s[i].first;
	for (int i=1;i<=n;i++)
		sum1[i]=sum1[i-1]+a[i];
	for (int i=n;i;i--)
		sum2[i]=sum2[i+1]+a[i];
	for (int i=0;i<=n;i++)
		if (1LL*A*i-sum1[i]<=m)
		{
			r=m-1LL*A*i+sum1[i];
			long long Lx=0,Rx=A;
			while (Rx-Lx>1)
			{
				long long Mid=(Rx+Lx)/2;
				if (check(Mid,i)) Lx=Mid; else Rx=Mid;
			}
			long long now;
			if (check(Rx,i)) now=Rx; else now=Lx;
			if (1LL*X*i+1LL*Y*now>ans)
			{
				ans=1LL*X*i+1LL*Y*now;
				anss1=i,anss2=now;
			}
		}
	printf("%lld\n",ans);
	for (int i=1;i<=n;i++)
	{
		if (i<=anss1) q[s[i].second]=A;
		else if (s[i].first>anss2) q[s[i].second]=s[i].first;
		else q[s[i].second]=anss2;
	}
	for (int i=1;i<=n;i++)
		printf("%lld ",q[i]);
	printf("\n");
	return 0;
}