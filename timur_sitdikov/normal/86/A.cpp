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
const ll LL_INF = 1e17 + 10;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

ll st10[15];

ll get_ans(ll v) {
	int ind = 0;
	for(; st10[ind] <= v; ind++);
	//cout << v << " " << st10[ind] - 1 - v << endl;
	return v * (st10[ind] - 1 - v);
}

void solve(){
	ll l, r;
	cin >> l >> r;
	st10[0] = 1;
	REP(i, 1, 15) {
		st10[i] = st10[i - 1] * 10;
	}
	ll ans = max(get_ans(l), get_ans(r));
	ll cur = r;
	REP(i, 0, 14) {
		if (st10[i] > r) {
			break;
		}
		cur -= cur % st10[i + 1];
		cur += 5 * st10[i];
		if (l <= cur && cur <= r) {
			ans = max(ans, get_ans(cur));
		}
	}
	cout << ans << endl;
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