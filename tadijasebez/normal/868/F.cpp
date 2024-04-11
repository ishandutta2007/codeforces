#include <stdio.h>
#define ll long long
const int N=100050;
const ll inf=9e18;
ll sum,pr[N],dp[N];
int cnt[N],a[N];
int min(int a, int b){ return a>b?b:a;}
void Add(int i){ sum+=cnt[a[i]]++;}
void Err(int i){ sum-=--cnt[a[i]];}
void Build(int l1, int r1, int l2, int r2)
{
	int i;
	if(l1>r2 || l2>r1)
	{
		for(i=l1;i<=r1;i++) Err(i);
		for(i=l2;i<=r2;i++) Add(i);
	}
	else
	{
		for(i=l1;i<l2;i++) Err(i);
		for(i=l2;i<l1;i++) Add(i);
		for(i=r1;i>r2;i--) Err(i);
		for(i=r2;i>r1;i--) Add(i);
	}
}
void Solve(int l, int r, int b, int e, int L, int R)
{
	if(l>r) return;
	int mid=l+r>>1,i,taj=mid;
	R=min(R,r-1);
	ll ans=inf;
	Build(b,e,L+1,mid);
	for(i=L;i<=min(R,mid-1);i++)
	{
		if(pr[i]+sum<ans)
		{
			ans=pr[i]+sum;
			taj=i;
		}
		Err(i+1);
	}
	dp[mid]=ans;
	for(i=min(R,mid-1);i>=taj;i--) Add(i+1);
	Solve(mid+1,r,taj+1,mid,taj,R);
	Solve(l,mid-1,taj+1,mid,L,taj);
	Build(taj+1,mid,b,e);
}
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) pr[i]=inf;
	while(k--)
	{
		Solve(1,n,0,-1,0,n-1);
		for(i=1;i<=n;i++) pr[i]=dp[i];
	}
	printf("%lld\n",dp[n]);
	return 0;
}