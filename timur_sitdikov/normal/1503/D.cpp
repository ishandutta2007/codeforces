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

const int MAXN = 5e5 + 5;

int v[MAXN][2];
int nxt[MAXN];
int ind[MAXN];
int used[MAXN];

int ans;
int c0, c1, l0, l1, r0, r1;

void rec_sol(int l, int r) {
	if (l > r) {
		// ans = min(c0, c1);
		return;
	}
	// Skip two adjacent
	if (nxt[l] == r) {
		used[l] = used[r] = 1;
		rec_sol(l + 1, r - 1);
		return;
	}
	// Init sequences
	c0 = c1 = 0;
	if (ind[l] == 0) {
		c1++;
	} else {
		c0++;
	}
	if (ind[r] == 0) {
		c1++;
	} else {
		c0++;
	}
	l0 = l;
	r0 = r;
	l1 = nxt[l];
	r1 = nxt[r];
	used[l0] = used[l1] = used[r0] = used[r1] = 1;
	// Move until possible, and check for a bad state
	int curl = l0, curr = r0;
	while(curl <= r1 || curr >= l1) {
		if (curl <= r1) {
			if (!used[curl]) {
				used[curl] = 1;
				int nxt_l1 = nxt[curl];
				if (nxt_l1 > l1) {
					// Bad situation
					ans = -1;
					return;
				}
				if (ind[curl] == 0) {
					c1++;
				} else {
					c0++;
				}
				used[nxt_l1] = 1;
				l1 = nxt_l1;
				curl++;
				l0 = curl;
			} else {
				curl++;
			}
		} else {
			if (!used[curr]) {
				used[curr] = 1;
				int nxt_r1 = nxt[curr];
				if (nxt_r1 < r1) {
					// Bad situation
					ans = -1;
					return;
				}
				if (ind[curr] == 0) {
					c1++;
				} else {
					c0++;
				}
				used[nxt_r1] = 1;
				r1 = nxt_r1;
				curr--;
				r0 = curr;
			} else {
				curr--;
			}
		}
	}
	ans += min(c0, c1);
	rec_sol(curl, curr);
}

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d%d", &v[i][0], &v[i][1]);
		if (v[i][0] <= n && v[i][1] <= n) {
			printf("-1\n");
			return;
		}
		nxt[v[i][0]] = v[i][1];
		nxt[v[i][1]] = v[i][0];
		ind[v[i][0]] = 0;
		ind[v[i][1]] = 1;
	}
	rec_sol(1, 2 * n);
	printf("%d\n", ans);
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