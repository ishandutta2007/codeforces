#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL N,A,B,C;
LL v[100010],premax[100010],sucmax[100010];

int main()
{
	scanf("%lld%lld%lld%lld",&N,&A,&B,&C);
	for (int i=1;i<=N;i++)scanf("%lld",&v[i]);
	premax[0] = -2e18;	
	for (int i=1;i<=N;i++)premax[i] = max(premax[i-1],A*v[i]);
	sucmax[N+1] = -2e18;
	for (int i=N;i>=1;i--)sucmax[i] = max(sucmax[i+1],C*v[i]);
	LL ans = -4e18;
	for (int i=1;i<=N;i++)
	ans = max(ans,B*v[i] + premax[i] + sucmax[i]);
	printf("%lld\n",ans);
}