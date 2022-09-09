#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=100050;
const int M=2*N;
const ll inf=9e18;
int a[N],b[N];
ll sum[M];
struct SegmentTree
{
	vector<ll> mn;
	int sz;
	SegmentTree(){}
	void init(int n){ sz=n;mn.clear();mn.assign(n*2,inf);}
	void Set(int i, ll f){ for(i+=sz-1;i;i>>=1) mn[i]=min(mn[i],f);}
	ll Get(int l, int r)
	{
		ll ret=inf;
		for(l+=sz-1,r+=sz-1;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) ret=min(ret,mn[l++]);
			if(r%2==0) ret=min(ret,mn[r--]);
		}
		return ret;
	}
} ST;
int main()
{
	int n,i;
	scanf("%i",&n);vector<int> sol;
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) scanf("%i",&b[i]);
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i]-b[i];
	for(i=n+1;i<=n*2;i++) sum[i]=sum[i-1]+a[i-n]-b[i-n];
	ST.init(2*n);
	for(i=1;i<=2*n;i++) ST.Set(i,sum[i]);
	for(i=1;i<=n;i++) if(sum[i-1]<=ST.Get(i,i+n-1)) sol.pb(i);
	//for(i:sol) printf("%i ",i);printf("\n");
	for(i=1;i<=n/2;i++) swap(a[i],a[n-i+1]),swap(b[i],b[n-i+1]);
	int tmp=b[1];for(i=1;i<n;i++) b[i]=b[i+1];b[n]=tmp;
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i]-b[i];
	for(i=n+1;i<=n*2;i++) sum[i]=sum[i-1]+a[i-n]-b[i-n];
	ST.init(2*n);
	for(i=1;i<=2*n;i++) ST.Set(i,sum[i]);
	for(i=1;i<=n;i++) if(sum[i-1]<=ST.Get(i,i+n-1)) sol.pb(n-i+1);
	sort(sol.begin(),sol.end());sol.erase(unique(sol.begin(),sol.end()),sol.end());
	printf("%i\n",sol.size());
	for(i:sol) printf("%i ",i);printf("\n");
	return 0;
}