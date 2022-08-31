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
int n,m;
long long pcs[233333],di[233333];
bool ok(long long cur)
{
	memset(di,0,sizeof(di));
	int lst=n;
	for(int i=1;i<=m;i++)
	{
		while(lst&&di[lst]==pcs[lst]) --lst;
		if(!lst) break;
		long long did=lst;
		while(did<cur)
		{
			long long cdc=min(cur-did,pcs[lst]-di[lst]);
			di[lst]+=cdc; did+=cdc;
			while(lst&&di[lst]==pcs[lst]) --lst;
			if(!lst) break;
		}
	}
	while(lst&&di[lst]==pcs[lst]) --lst;
	return !lst;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%I64d",pcs+i);
	long long l=0,r=1000000000000000000LL;
	while(l<r)
	{
		long long mid=(l+r)>>1;
		if(ok(mid)) r=mid; else l=mid+1;
	}
	cout<<l;
}