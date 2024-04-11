#include <stdio.h>
#include <algorithm>
#define ll long long
const int N=200050;
const int S=448;
const int M=1000500;
int C[M],A[N];
ll sol;
void Add(int x)
{
	sol-=(ll)C[x]*C[x]*x;
	C[x]++;
	sol+=(ll)C[x]*C[x]*x;
}
void Err(int x)
{
	sol-=(ll)C[x]*C[x]*x;
	C[x]--;
	sol+=(ll)C[x]*C[x]*x;
}
struct Query
{
	int l,r,i;
	inline bool operator < (const Query &b) const
	{
		return (r/S<b.r/S)||(r/S==b.r/S && l<b.l);
	}
} Q[N];
ll ans[N];
int main()
{
	int n,q,i;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&A[i]);
	for(i=0;i<q;i++) scanf("%i %i",&Q[i].l,&Q[i].r),Q[i].i=i;
	int l=1,r=0;
	std::sort(Q,Q+q);
	for(i=0;i<q;i++)
	{
		while(r<Q[i].r) Add(A[++r]);
		while(r>Q[i].r) Err(A[r--]);
		while(l<Q[i].l) Err(A[l++]);
		while(l>Q[i].l) Add(A[--l]);
		ans[Q[i].i]=sol;
	}
	for(i=0;i<q;i++) printf("%lld\n",ans[i]);
	return 0;
}