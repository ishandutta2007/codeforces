#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

/*const int N=200050;
const int M=70*N;
const ll inf=2e18;
int q,root,tsz,ls[M],rs[M];
ll st[M];
void modify(int&v,ll l,ll r,ll qi,ll qv) {
	if (!v) v=++tsz;
	st[v]+=qv;
	if (l==r) return;
	ll mid=l+r>>1;
	if (qi<=mid) modify(ls[v],l,mid,qi,qv);
	else modify(rs[v],mid+1,r,qi,qv);
}

ll query(int v,ll l,ll r,ll ql,ll qr) {
	if (!v||l>r||l>qr||r<ql) return 0;
	if (ql<=l&&r<=qr) return st[v];
	ll mid=l+r>>1;
	return query(ls[v],l,mid,ql,qr)+query(rs[v],mid+1,r,ql,qr);
}*/

const int N=200050;
int q;
ll ans[N];
map<ll,VI> qs;
map<ll,VI> occ;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>q;
	rep(i,0,q) {
		char op;
		cin>>op;
		ll x;
		cin>>x;
		if (op=='+') occ[x].pb(i);
		else if (op=='-') occ[x].pb(i);
		else qs[x].pb(i);
	}
	rep(i,0,q) ans[i]=-1;
	for (auto& p:qs) {
		set<int> ids;
		for (int i:p.se) ids.insert(i);
		ll v=p.fi;
		while (!ids.empty()) {
			if (SZ(occ[v])==0) {
				for (int i:ids) ans[i]=v;
				break;
			}
			while (!ids.empty()&&*ids.begin()<occ[v][0]) {
				ans[*ids.begin()]=v;
				ids.erase(ids.begin());
			}
			int sz=SZ(occ[v]);
			rep(i,0,sz) {
				if (i&1) {
					int nxt=(i==sz-1?1e9:occ[v][i+1]);
					while (true) {
						auto it=ids.lower_bound(occ[v][i]);
						if (it!=ids.end()&&*it>=occ[v][i]&&*it<nxt) {
							ans[*it]=v;
							ids.erase(it);
						} else break;
					}
				}
			}
			v+=p.fi;
		}
	}
	rep(i,0,q) if (ans[i]!=-1) cout<<ans[i]<<"\n";
}