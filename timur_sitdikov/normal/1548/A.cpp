#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double DOUBLE;
typedef complex<double> point;
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

#define x0 gray_cat_x0
#define y0 gray_cat_y0
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
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;

const int MAXN = 3e5 + 5;

set<int> st[MAXN];
set<int> superb;

void solve(){
	int n, m, t, a, b, q;
	scanf("%d%d", &n, &m);
	REPN(i, 1, n) {
		superb.insert(i);
	}
	REPN(i, 1, m) {
		scanf("%d%d", &a, &b);
		st[a].insert(b);
		st[b].insert(a);
		superb.erase(min(a, b));
	}
	scanf("%d", &q);
	while(q--) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d", &a, &b);
			st[a].insert(b);
			st[b].insert(a);
			superb.erase(min(a, b));
		} else if (t == 2) {
			scanf("%d%d", &a, &b);
			st[a].erase(b);
			st[b].erase(a);
			if (SZ(st[a]) == 0 || *st[a].rbegin() < a) {
				superb.insert(a);
			}
			if (SZ(st[b]) == 0 || *st[b].rbegin() < b) {
				superb.insert(b);
			}
		} else {
			printf("%d\n", SZ(superb));
		}
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