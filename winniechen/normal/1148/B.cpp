#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 200005
int n,m,k;
long long t1,t2,a[N],b[N],ans;
int main()
{
	scanf("%d%d%lld%lld%d",&n,&m,&t1,&t2,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	if(k>=n)return puts("-1"),0;
	for(int i=1;i<=k+1&&i<=n;i++)
	{
		int p=lower_bound(b+1,b+m+1,a[i]+t1)-b;
		p+=k+1-i;if(p>m)return puts("-1"),0;ans=max(ans,b[p]+t2);
	}
	printf("%lld\n",ans);
}