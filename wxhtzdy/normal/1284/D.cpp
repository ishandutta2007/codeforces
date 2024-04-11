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
int n,sa[N],ea[N],sb[N],eb[N];

bool check() {
	vector<PII> v;
	rep(i,0,n) {
		v.pb(mp(i,0));
		v.pb(mp(i,1));
	}
	sort(all(v),[&](PII x,PII y) {
		int vx=(x.se==0?sa[x.fi]:ea[x.fi]);
		int vy=(y.se==0?sa[y.fi]:ea[y.fi]);
		if (vx==vy) return x.se<y.se;
		else return vx<vy;	
	});
	multiset<int> zx,zy;
	rep(i,0,2*n) {
		int id=v[i].fi;
		if (v[i].se==0) {
			if (SZ(zx)) {
				if (*prev(zx.end())>eb[id]||*zy.begin()<sb[id]) return false;
			}
			zx.insert(sb[id]);
			zy.insert(eb[id]);
		} else {
			zx.erase(zx.find(sb[id]));
			zy.erase(zy.find(eb[id]));
		}
	}
	return true;
}

int main() {
	VI v;
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d%d%d",sa+i,ea+i,sb+i,eb+i);
	}
	rep(samo_jako___ide_plin_i_zemni_gas,0,2) {
		if (!check()) {
			puts("NO");
			return 0;
		}
		rep(i,0,n) {
			swap(sa[i],sb[i]);
			swap(ea[i],eb[i]);
		}
	}
	puts("YES");
}