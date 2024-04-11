#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define pb push_back
const int N=100050;
const ll inf=1e14+50;
struct SegmentTree
{
	vector<ll> id;
	int sum[1<<18];
	SegmentTree(){ for(int i=0;i<(1<<18);i++) sum[i]=0;id.clear();}
	void Push(ll x){ id.pb(x);}
	void Build(){ sort(id.begin(),id.end());id.erase(unique(id.begin(),id.end()),id.end());}
	int FindL(ll x){ return lower_bound(id.begin(),id.end(),x)-id.begin();}
	int FindR(ll x){ return upper_bound(id.begin(),id.end(),x)-id.begin()-1;}
	void Set(ll x, int f){ x=FindL(x);for(x+=1<<17;x;x>>=1) sum[x]+=f;}
	int Get(ll l, ll r)
	{
		int ret=0;l=FindL(l);r=FindR(r);
		for(l+=1<<17,r+=1<<17;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) ret+=sum[l++];
			if(r%2==0) ret+=sum[r--];
		}
		return ret;
	}
	void Init(){ for(int i=0;i<(1<<18);i++) sum[i]=0;}
} Tree;
ll a[N];
ll Count(int n, ll mid)
{
	ll ret=0;Tree.Init();
	int i;Tree.Set(0,1);
	for(i=1;i<=n;i++)
	{
		ret+=Tree.Get(a[i]-mid+1,inf);
		Tree.Set(a[i],1);
	}
	return (ll)n*(n+1)/2-ret;
}
int main()
{
	int n,i;ll k;
	scanf("%i %lld",&n,&k);Tree.Push(0);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]+=a[i-1],Tree.Push(a[i]);
	Tree.Build();
	ll top=inf,bot=-inf,mid,ans;
	while(top>=bot)
	{
		mid=top+bot>>1;
		//printf("mid:%lld %lld\n",mid,Count(n,mid));
		if(Count(n,mid)>=k) ans=mid,bot=mid+1;
		else top=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}