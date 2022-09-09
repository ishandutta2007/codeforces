#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#include <bits/stdc++.h>
using namespace std;
#define ldb double
ldb dp[1<<20];
ldb o[1<<20];
int n;
vector<ldb> p;
int main()
{
	int k,i,j;
	scanf("%i %i",&n,&k);
	vector<ldb> sol(n,0);
	p.resize(n);
	for(ldb &f:p) cin>>f;
	for(int mask=0;mask<1<<n;mask++)
	{
		for(i=0;i<n;i++) if((mask>>i)&1) o[mask]+=p[i];
	}
	dp[0]=1;
	for(int mask=1;mask<1<<n;mask++)
	{
		dp[mask]=0;
		for(int j=0;j<n;j++) if((mask>>j)&1) dp[mask]+=dp[mask^(1<<j)]*p[j];
		if(o[mask]==1) continue;
		dp[mask]/=(1-o[mask]);
	}
	for(int mask=0;mask<1<<n;mask++) if(__builtin_popcount(mask)<k)
	{
		for(i=0;i<n;i++) if(!((mask>>i)&1)) sol[i]+=p[i]*dp[mask];
	}
	for(ldb f:sol) cout<<fixed<<setprecision(12)<<f<<" ";
	return 0;
}