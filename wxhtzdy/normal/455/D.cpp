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
const ll mod2=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
const int blk=int(sqrt(N))+5;
int n,a[N],q;

struct ds {
	int f[blk][N];
	deque<int> dq[blk];
	void build() {
		rep(i,0,blk) rep(j,0,n) f[i][j]=0;
		rep(i,0,n) {
			f[i/blk][a[i]]++;
			dq[i/blk].pb(a[i]);
		}
	}
	void modify(int l,int r) {
		int z=dq[r/blk][r%blk];
		dq[r/blk].erase(dq[r/blk].begin()+r%blk);
		dq[l/blk].insert(dq[l/blk].begin()+l%blk,z);
		f[r/blk][z]--; f[l/blk][z]++;
		rep(i,l/blk,r/blk) {
			z=dq[i].back(); dq[i].pop_back();
			dq[i+1].push_front(z);
			f[i][z]--; f[i+1][z]++;
		}
	}
	int query(int l,int r,int k) {
		if (l/blk==r/blk) {
			int ans=0;
			rep(i,l%blk,r%blk+1) ans+=(dq[l/blk][i]==k?1:0);
			return ans;
		}
		int ans=0;
		rep(i,l%blk,SZ(dq[l/blk])) ans+=(dq[l/blk][i]==k?1:0);
		rep(i,l/blk+1,r/blk) ans+=f[i][k];
		rep(i,0,r%blk+1) ans+=(dq[r/blk][i]==k?1:0);
		return ans;
	}
} d;

int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i),--a[i];
	d.build();
	scanf("%d",&q);
	int ans=0;
	while (q--) {
		int t;
		scanf("%d",&t);
		if (t==1) {
			int l,r;
			scanf("%d%d",&l,&r);
			l=(l+ans-1)%n;
			r=(r+ans-1)%n;
			if (l>r) swap(l,r);
			d.modify(l,r);
		} else {
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			l=(l+ans-1)%n;
			r=(r+ans-1)%n;
			k=(k+ans-1)%n;
			if (l>r) swap(l,r);
			ans=d.query(l,r,k);
			printf("%d\n",ans);
		}
	}
	return 0;
}