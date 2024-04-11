#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n;
int lx[Maxn],rx[Maxn];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&lx[i],&rx[i]);
	sort(lx+1,lx+n+1);
	sort(rx+1,rx+n+1);
	long long ans=0;
	for (int i=1;i<=n;i++)
		ans+=max(lx[i],rx[i])+1;
	printf("%lld\n",ans);
	return 0;
}