#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
int _,n,a[N],ans[N],b[N];
void solve() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i),b[i]=i;
	//sort(a,a+n);
	sort(b,b+n,[&](int i,int j){ return a[i]<a[j]; });
	if (n%2==0) {
		rep(i,0,n/2) {
			ans[i]=a[n-i-1];
			ans[n-i-1]=-a[i];
		}
	} else {
		int id=-1;
		rep(i,0,n-3) if (a[b[i]]==a[b[i+1]]&&a[b[i+1]]==a[b[i+2]]) id=i;
		if (id!=-1) {
			ans[b[id]]=1;
			ans[b[id+1]]=1;
			ans[b[id+2]]=-2;
			VI v;
			rep(i,0,n) if (i<id||i>id+2) v.pb(i);
			rep(i,0,SZ(v)/2) {
				ans[b[v[i]]]=a[b[v[SZ(v)-i-1]]];
				ans[b[v[SZ(v)-i-1]]]=-a[b[v[i]]];
			}
		} else {
			PII p={-1,-1};
			rep(i,0,n) {
				if (p.fi!=-1) break;
				rep(j,i+1,n) if (a[b[i]]+a[b[j]]!=0) p.fi=i,p.se=j;
			}
			assert(p.fi!=-1&&p.se!=-1);
			rep(i,0,n) if (i!=p.fi&&i!=p.se) id=i;
//			printf("%d %d %d\n",p.fi,p.se,id);
			ans[b[p.fi]]=a[b[id]];
			ans[b[p.se]]=a[b[id]];
			ans[b[id]]=-(a[b[p.fi]]+a[b[p.se]]);
			VI v;
			rep(i,0,n) if (i!=p.fi&&i!=p.se&&i!=id) v.pb(i);
			rep(i,0,SZ(v)/2) {
				ans[b[v[i]]]=a[b[v[SZ(v)-i-1]]];
				ans[b[v[SZ(v)-i-1]]]=-a[b[v[i]]];
			}
		}
	}
	ll sum=0;
	rep(i,0,n) printf("%d ",ans[i]),sum+=ans[i]; puts("");
	assert(sum<=1e9);
}
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}