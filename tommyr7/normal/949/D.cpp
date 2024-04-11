#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n,d,b;
int a[Maxn],cnt[Maxn],aa[Maxn];
bool calc(int dis,int pos)
{
	int t=(dis+d-1)/d,tot=min(pos,n-pos+1);
	return (t<=tot);
}
bool check(int x)
{
	for (int i=1;i<=n;i++)
		a[i]=aa[i];
	for (int i=x+1;i<=n;i++)
		cnt[i]=b;
	int pos=x+1;
	for (int i=1;i<=n;i++)
	{
		while (a[i]>0)
		{
			if (calc(abs(pos-i),pos))
			{
				int del=min(a[i],cnt[pos]);
				a[i]-=del;
				cnt[pos]-=del;
				if (cnt[pos]==0) ++pos;
				if (pos+x-1>=n) return true;
			} else break;
		}
	}
	return false;
}
int main()
{
	scanf("%d%d%d",&n,&d,&b);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		aa[i]=a[i];
	int lx=0,rx=(n+1)/2;
	while (rx-lx>1)
	{
		int mid=(lx+rx)/2;
		if (check(mid)) rx=mid; else lx=mid;
	}
	if (check(lx)) printf("%d\n",lx); else printf("%d\n",rx);
	return 0;
}