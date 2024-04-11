#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long
map<ll,int> id;
const int N=100050;
const int S=317;
ll dp[N],p[N];
int t[N];
int cnt[4*N],left[N],right[N],index[N],clock;
ll sol;
void AddR(int pos)
{
	sol+=cnt[left[pos]];
	cnt[index[pos]]++;
}
void ErrR(int pos)
{
	cnt[index[pos]]--;
	sol-=cnt[left[pos]];
}
void AddL(int pos)
{
	sol+=cnt[right[pos]];
	cnt[index[pos]]++;
}
void ErrL(int pos)
{
	cnt[index[pos]]--;
	sol-=cnt[right[pos]];	
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
	int n,q,i,l,r,k;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&t[i]);
	id[ 0]=++clock;
	id[ k]=++clock;
	id[-k]=++clock;
	left[0]=id[-k];
	index[0]=id[0];
	right[0]=id[k];
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&p[i]);
		dp[i]=dp[i-1]+p[i]*(t[i]==1?1:-1);
		if(id[dp[i]-k]==0) id[dp[i]-k]=++clock;
		if(id[dp[i]  ]==0) id[dp[i]  ]=++clock;
		if(id[dp[i]+k]==0) id[dp[i]+k]=++clock;
		left[i] =id[dp[i]-k];
		index[i]=id[dp[i]  ];
		right[i]=id[dp[i]+k];
	}
	scanf("%i",&q);
	for(i=0;i<q;i++)
	{
		scanf("%i %i",&Q[i].l,&Q[i].r);
		Q[i].i=i+1;
		Q[i].l--;
	}
	sort(Q,Q+q);
	l=0,r=-1;
	for(i=0;i<q;i++)
	{
		while(r<Q[i].r) AddR(++r);
		while(r>Q[i].r) ErrR(r--);
		while(l>Q[i].l) AddL(--l);
		while(l<Q[i].l) ErrL(l++);
		ans[Q[i].i]=sol;
	}
	for(i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}