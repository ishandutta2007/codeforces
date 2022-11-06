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
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 9;

const int MAXN = 2e5 + 5;

vi g[MAXN];

int par[MAXN];
int cnt[MAXN];
ll mul[MAXN];

int get_par(int v) {
	return v == par[v] ? v : par[v] = get_par(par[v]);
}

ll st2[MAXN];

ll pow_mod(ll a, ll st) {
	ll ans = 1ll;
	for(; st; st >>= 1) {
		if (st & 1) {
			ans = (ans * a) % MOD;
		}
		a = (a * a) % MOD;
	}
	return ans;
}

ll get_inv(ll a) {
	return pow_mod(a, MOD - 2);
}

void solve(){
	int n, m;
	scanf("%d%d", &n, &m);
	st2[0] = 1;
	REPN(i, 1, n) {
		st2[i] = (st2[i - 1] * 2) % MOD;
		par[i] = i;
		mul[i] = 1;
		cnt[i] = 0;
	}
	ll ans = 1ll;
	REP(i, 0, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		a = get_par(a), b = get_par(b);
		if (a == b) {
			//ans = (ans * get_inv(st2[cnt[a]])) % MOD;
			cnt[a]++;
			mul[a] = (mul[a] * 2) % MOD;
			ans = (ans * 2) % MOD;
			//ans = ans * (st2[cnt[a]]) % MOD;
		} else {
			cnt[a] += cnt[b];
			mul[a] = (mul[a] * mul[b]) % MOD;
			par[b] = a;
		}
		printf("%lld\n", (ans + MOD - 1) % MOD);
	}
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}