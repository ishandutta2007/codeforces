#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
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

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

vi g[MAXN];
int val[MAXN];
int used_mex[MAXN];
int mex[MAXN];
int used[MAXN];

int mex_xor[MAXN];

void dfs(int s) {
	used[s] = 1;
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		if (!used[to]) {
			dfs(to);
		}
	}
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		used_mex[mex[to]] = s;
	}
	for(mex[s] = 0; used_mex[mex[s]] == s; mex[s]++);
}

void solve(){
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	REPN(i, 1, n) {
		scanf("%d", &val[i]);
	}
	REP(i, 0, m) {
		scanf("%d%d", &a, &b);
		g[a].pb(b);
	}
	REPN(i, 1, n) {
		if (!used[i]) {
			dfs(i);
		}
	}
	REPN(i, 1, n) {
		mex_xor[mex[i]] ^= val[i];
	}
	int ind = 0;
	for(ind = n; ind >= 0; ind--) {
		if (mex_xor[ind]) {
			break;
		}
	}
	if (ind == -1) {
		printf("LOSE\n");
		return;
	}
	REPN(i, 1, n) {
		if (mex[i] == ind && (val[i] ^ mex_xor[ind]) < val[i]) {
			val[i] ^= mex_xor[ind];
			REP(j, 0, SZ(g[i])) {
				int to = g[i][j];
				val[to] ^= mex_xor[mex[to]];
				mex_xor[mex[to]] = 0;
			}
			break;
		}
	}
	printf("WIN\n");
	REPN(i, 1, n) {
		printf("%d ", val[i]);
	}
	putchar('\n');
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