#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long a[500005],x[500005],y[500005],d[500005],cf[300005];
long long n,m,k,t;
inline long long pd(long long mid)
{
	long long l=0,r=0;
	memset(cf,0,sizeof cf);
	for(long long i=1;i<=k;i++)
	{
		if(d[i]>mid)
			++cf[x[i]],--cf[y[i]+1];
	}
	for(long long i=1;i<=n;i++)
	{
		cf[i]+=cf[i-1];
		if(!cf[i]) ++l;
	}
	long long rtn=(n*3)-(l*2)+1;
	if(l==n&&r==0) rtn=0;
	return rtn;
}
inline bool cmp(long long x,long long y)
{
	return x>y;
}
signed main(long long argc, char** argv) {
	ios::sync_with_stdio(false);
	cin >> m >> n >> k >> t; 
	for(long long i=1;i<=m;i++)
		cin >> a[i];
	for(long long i=1;i<=k;i++)
		cin >> x[i] >> y[i] >> d[i];
	long long l=1,r=m,ans=0;
	sort(a+1,a+m+1,cmp);
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(pd(a[mid])<=t) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout << ans;
	return 0;
}