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

const int MAXN = 205;
char s[MAXN];

int cnt[MAXN][MAXN];
char ans[MAXN];

vector<char> g[MAXN][MAXN];
vector<char> cur;

int calc_cnt(int n) {
	return n * (n + 1) / 2;
}

void process(int l, int r) {
	int n = r - l + 1;
	REPN(i, 1, n){
		REPN(j, 'a', 'z') {
			cnt[i][j] = 0;
		}
	}
	printf("? %d %d\n", l, r);
	fflush(stdout);
	REPN(i, 1, n * (n + 1) / 2) {
		scanf("%s", &s[0]);
		int len = strlen(s);
		REP(j, 0, len) {
			cnt[len][s[j]]++;
		}
	}
	
	int lim = (n - 1) / 2;
	REPN(j, 1, lim) {
		REPN(k, j + 1, lim + 1) {
			REPN(t, 'a', 'z') {
				cnt[k][t] -= cnt[j][t];
			}
		}
		cur.clear();
		REPN(k, 'a', 'z') {
			REP(t, 0, cnt[j][k] - cnt[j + 1][k]) {
				cur.pb(k);
			}
		}
		int l1 = j;
		int r1 = n + 1 - j;
		REP(k, 0, SZ(cur)) {
			g[l1 + l - 1][r1 + l - 1].pb(cur[k]);
			g[r1 + l - 1][l1 + l - 1].pb(cur[k]);
		}
	}
	cur.clear();
	REPN(k, 'a', 'z') {
		REP(t, 0, cnt[lim + 1][k]) {
			cur.pb(k);
		}
	}
	if (n % 2) {
		ans[n / 2 + l] = cur[0];
	} else {
		int j = lim + 1;
		int l1 = j;
		int r1 = n + 1 - j;
		REP(k, 0, SZ(cur)) {
			g[l1 + l - 1][r1 + l - 1].pb(cur[k]);
			g[r1 + l - 1][l1 + l - 1].pb(cur[k]);
		}
	}
}

int used[MAXN];
void go(int s, int n) {
	used[s] = 1;
	REPN(i, 1, n) {
		if (!used[i] && !g[s][i].empty()) {
			char ee = g[s][i][0];
			if (ans[s] == ee) {
				ee = g[s][i][1];
			}
			ans[i] = ee;
			go(i, n);
		}
	}
}

void solve(){
	/*REPN(n, 1, 100) {
		int cnt = calc_cnt(n) + calc_cnt(n / 2 + 1) + calc_cnt((n + 1) / 2);
		int lim = (int)(0.777 * (n + 1) * (n + 1) + 1 - EPS);
		printf("%d: %d %d\n", n, cnt, lim);
	}*/
	
	int n;
	scanf("%d", &n);
	process(1, n);
	if (n == 2) {
		process(1, 1);
	}
	if (n > 2 && n % 2 == 0) {
		int l = n / 2 + 1;
		process(l, n);
		process(1, l);
	}
	if (n > 2 && n % 2 == 1) {
		int l = n / 2 + 1;
		process(l, n);
		process(1, l - 1);
	}
	REPN(i, 1, n) {
		if (!used[i] && ans[i]) {
			go(i, n);
		}
	}
	printf("! %s\n", ans + 1);
	fflush(stdout);
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