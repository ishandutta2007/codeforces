#include <stdio.h>
#include <algorithm>
const int N=100050;
const int S=317;
int C[N],sol;
void Add(int x)
{
	if(x<N)
	{
		C[x]++;
		if(C[x]==x) sol++;
		if(C[x]==x+1) sol--;
	}
}
void Err(int x)
{
	if(x<N)
	{
		C[x]--;
		if(C[x]==x) sol++;
		if(C[x]==x-1) sol--;
	}
}
struct Query
{
	int l,r,i;
	Query(){}
	Query(int a, int b, int c){l=a,r=b,i=c;}
	inline bool operator < (const Query &b) const
	{
		return (r/S<b.r/S)||(r/S==b.r/S && l<b.l);
	}
} Q[N];
int a[N],ans[N];
int main()
{
	int n,q,i;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=0;i<q;i++) scanf("%i %i",&Q[i].l,&Q[i].r),Q[i].i=i;
	std::sort(Q,Q+q);
	int l=1,r=0;
	for(i=0;i<q;i++)
	{
		while(r<Q[i].r) Add(a[++r]);
		while(r>Q[i].r) Err(a[r--]);
		while(l<Q[i].l) Err(a[l++]);
		while(l>Q[i].l) Add(a[--l]);
		ans[Q[i].i]=sol;
	}
	for(i=0;i<q;i++) printf("%i\n",ans[i]);
	return 0;
}