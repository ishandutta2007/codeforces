#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
typedef double DOUBLE;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 10;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 5e5 + 5;

vi g[MAXN];
ll v[MAXN];
int per[MAXN];

vector<ll> vals;

bool cmp(int a, int b) {
	return g[a] < g[b];
}

void solve(){
	int n, m;
	scanf("%d%d", &n, &m);
	REPN(i, 1, n) {
		g[i].clear();
		scanf("%lld", &v[i]);
		per[i] = i;
	}
	REP(i, 0, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[b].pb(a);
	}
	REPN(i, 1, n) {
		SORT(g[i]);
	}
	sort(per + 1, per + n + 1, cmp);
	vals.clear();
	for(int i = 1; i <= n; ) {
		int j;
		ll cur = v[per[i]];
		for(j = i + 1; j <= n && g[per[j]] == g[per[i]]; j++) {
			cur += v[per[j]];
		}
		if (!g[per[i]].empty()) {
			vals.pb(cur);
		}
		i = j;
	}
	ll ans = 0ll;
	REP(i, 0, SZ(vals)) {
		ans = gcd(ans, vals[i]);
	}
	printf("%lld\n", ans);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while(t--){
        solve();    
    }
}