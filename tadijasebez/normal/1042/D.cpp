#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
struct SegmentTree
{
	vector<int> sum;
	int sz;
	SegmentTree(){}
	void init(int n){ sz=n,sum.resize(n*2);}
	void Set(int i, int f){ for(i+=sz;i;i>>=1) sum[i]+=f;}
	int Get(int l, int r)
	{
		int ret=0;
		for(l+=sz,r+=sz;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) ret+=sum[l],l++;
			if(r%2==0) ret+=sum[r],r--;
		}
		return ret;
	}
} ST;
vector<ll> id;
int Find(ll x){ return lower_bound(id.begin(),id.end(),x)-id.begin();}
const int N=200050;
ll a[N],sum[N];
int main()
{
	int n,i;ll t;
	scanf("%i %lld",&n,&t);id.pb(0);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]),sum[i]=a[i]+sum[i-1],id.pb(sum[i]),id.pb(sum[i]-t+1);
	sort(id.begin(),id.end());id.erase(unique(id.begin(),id.end()),id.end());
	ST.init(id.size());
	ll sol=0;
	for(i=1;i<=n;i++)
	{
		ST.Set(Find(sum[i-1]),1);
		sol+=ST.Get(Find(sum[i]-t+1),id.size()-1);
	}
	printf("%lld\n",sol);
	return 0;
}