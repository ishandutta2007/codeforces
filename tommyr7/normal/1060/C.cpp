#include <bits/stdc++.h>
#define Maxn 2007
using namespace std;
int n,m;
int a[Maxn],b[Maxn];
int s1[Maxn],s2[Maxn];
int cnt1[Maxn],cnt2[Maxn];
int x,ans=0;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	s1[0]=0;
	for (int i=1;i<=n;i++)
		s1[i]=s1[i-1]+a[i];
	for (int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	scanf("%d",&x);
	s2[0]=0;
	for (int i=1;i<=m;i++)
		s2[i]=s2[i-1]+b[i];
	for (int i=0;i<=2000;i++)
		cnt1[i]=4000007,cnt2[i]=4000007;
	cnt1[0]=0,cnt2[0]=0;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			cnt1[j-i+1]=min(cnt1[j-i+1],s1[j]-s1[i-1]);
	for (int i=1;i<=m;i++)	
		for (int j=i;j<=m;j++)
			cnt2[j-i+1]=min(cnt2[j-i+1],s2[j]-s2[i-1]);
	for (int i=1;i<=m;i++)
	{
		int lx=0,rx=n,now=x/cnt2[i];
		while (rx-lx>1)
		{
			int mid=(lx+rx)/2;
			if (cnt1[mid]<=now) lx=mid; else rx=mid;
		}
		int j=rx;
		if (cnt1[rx]<=now) j=rx; else j=lx;
		ans=max(ans,i*j);
	}
	printf("%d\n",ans);
	return 0;
}