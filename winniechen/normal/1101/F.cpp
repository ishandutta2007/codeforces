#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 405
#define ll long long
int a[N],n,m,s,t,f,c,l,r;ll ans;
inline bool check(int x)
{
	register int i,tc=c;register int now=x;
	for(i=s;i<t;i++)
	{
		if(a[i+1]-a[i]>x)return 0;
		if(a[i+1]-a[i]>now)
		{
			if(!tc)return 0;
			tc--;now=x;
		}
		now-=a[i+1]-a[i];
	}return 1;
}
int main()
{
	scanf("%d%d",&n,&m);l=0,r=1<<30;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	while(m--)
	{
		scanf("%d%d%d%d",&s,&t,&f,&c);if(s>t)swap(s,t);
		if(check(ans/f))continue;
		l=(ans/f)+1;r=a[t]-a[s];
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(check(mid))r=mid;else l=mid+1;
		}ans=max((ll)l*f,ans);
	}
	printf("%lld\n",ans);
}