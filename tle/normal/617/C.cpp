#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
int n,x1,y1,x2,y2;
int xx[2333],yy[2333];
#define ll long long
pair<ll,ll> ds[2333];
ll d1[2333],d2[2333],ans;
int main()
{
	scanf("%d%d%d%d%d",&n,&x1,&y1,&x2,&y2);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",xx+i,yy+i);
		ds[i].first=(ll)(xx[i]-x1)*(xx[i]-x1)+(ll)(yy[i]-y1)*(yy[i]-y1);
		ds[i].second=(ll)(xx[i]-x2)*(xx[i]-x2)+(ll)(yy[i]-y2)*(yy[i]-y2);
	}
	sort(ds+1,ds+1+n);
	ans=0;
	for(int j=n;j>=1;j--) ans=max(ans,ds[j].second);
	for(int i=1;i<=n;i++)
	{
		ll mm=0;
		for(int j=n;j>i;j--) mm=max(mm,ds[j].second);
		ans=min(ans,mm+ds[i].first);
	}
	printf("%I64d\n",ans);
}