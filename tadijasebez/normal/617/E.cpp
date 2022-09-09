#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long
const int N=100050;
const int S=317;
const int M=2000050;
int C[M],k;
ll sol;
void Add(int x)
{
	sol+=C[x^k];
	C[x]++;
}
void Err(int x)
{
	C[x]--;
	sol-=C[x^k];
}
int A[N],dp[N];
struct Query
{
	int l,r,i;
	Query(){}
	Query(int a, int b, int c){ l=a,r=b,i=c;}
	inline bool operator < (const Query &b) const
	{
		return (r/S<b.r/S) || (r/S==b.r/S && l<b.l);
	}
} Q[N];
ll ans[N];
int main()
{
	int n,q,i;
	scanf("%i %i %i",&n,&q,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&A[i]);
		dp[i]=dp[i-1]^A[i];
	}
	for(i=1;i<=q;i++)
	{
		scanf("%i %i",&Q[i].l,&Q[i].r);
		Q[i].l--;
		Q[i].i=i;
	}
	sort(Q+1,Q+1+q);
	int l=0,r=-1;
	for(i=1;i<=q;i++)
	{
		while(r<Q[i].r) Add(dp[++r]);
		while(r>Q[i].r) Err(dp[r--]);
		while(l<Q[i].l) Err(dp[l++]);
		while(l>Q[i].l) Add(dp[--l]);
		ans[Q[i].i]=sol;
	}
	for(i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}