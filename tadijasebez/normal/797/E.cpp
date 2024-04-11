#include <stdio.h>
const int N=100050;
const int S=317;
int dp[N][S],n,a[N];
int Solve(int p, int k)
{
	if(p>n) return 0;
	if(dp[p][k]) return dp[p][k];
	dp[p][k]=Solve(p+a[p]+k,k)+1;
	return dp[p][k];
}
int Solve2(int p, int k)
{
	if(p>n) return 0;
	return Solve2(p+a[p]+k,k)+1;
}
int main()
{
	int q,p,k;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i",&a[i]);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&p,&k);
		if(k<S) printf("%i\n",Solve(p,k));
		else printf("%i\n",Solve2(p,k));
	}
	return 0;
}