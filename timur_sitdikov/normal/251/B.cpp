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

vi p, p_inv, q, s, tmp, tmp1;
int n, k;

int v1, v2;

bool check(vi &p, int &val) {
	tmp = s;
	REPN(l, 1, k) {
		tmp1 = tmp;
		REP(i, 0, n) {
			tmp[i] = p[tmp1[i]];
		}
		if (tmp == q) {
			if (l == 1 && k == 1) {
				return true;
			}
			if (l > 1 && l % 2 == k % 2) {
				return true;
			}
			val = l;
			return false;
		}
	}
	return false;
}

void solve(){
	scanf("%d%d", &n, &k);
	p.resize(n);
	p_inv.resize(n);
	q.resize(n);
	s.resize(n);
	REP(i, 0, n) {
		scanf("%d", &p[i]);
		p[i]--;
		p_inv[p[i]] = i;
	}
	REP(i, 0, n) {
		scanf("%d", &q[i]);
		q[i]--;
	}
	REP(i, 0, n) {
		s[i] = i;
	}
	if (s == q) {
		printf("NO\n");
		return;
	}
	if (check(p, v1)) {
		printf("YES\n");
		return;
	}
	if (check(p_inv, v2)) {
		printf("YES\n");
		return;
	}
	if (k % 2 == 1 && (v1 == 1 && v2 != 1 || v2 == 1 && v1 != 1)) {
		printf("YES\n");
		return;
	}
	printf("NO\n");
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