//By zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <math.h>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define mp make_pair
int n,m,k;
ll p,h[233333],a[233333],ch[233333];
bool ok(ll x)
{
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	for(int i=1;i<=n;i++)
	{
		ch[i]=x;
		if(ch[i]-m*a[i]>=0) continue;
		pq.push(mp(ch[i]/a[i]-1,i));
	}
	int cnt=0;
	for(;cnt<m*k;cnt++)
	{
		if(pq.empty()) break;
		pii cur=pq.top();pq.pop();
		if(cur.first<cnt/k) return 0;
		int i=cur.second; ch[i]+=p;
		if(ch[i]-m*a[i]>=0) continue;
		pq.push(mp(ch[i]/a[i]-1,i));
	}
	for(int i=1;i<=n;i++)
	{
		if(ch[i]-m*a[i]>=h[i]) continue;
		cnt+=(h[i]-ch[i]+m*a[i]+p-1)/p;
		if(cnt>m*k) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d%d%I64d",&n,&m,&k,&p);
	ll l=0,r=20000000000000LL;
	for(int i=1;i<=n;i++) scanf("%I64d%I64d",h+i,a+i), r=max(r,m*a[i]+h[i]);
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(ok(mid)) r=mid; else l=mid+1;
	}
	printf("%I64d\n",l);
}