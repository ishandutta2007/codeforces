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

int p[MAXN];

int used[MAXN];

vi v;

int ask(int pos) {
	printf("? %d\n", pos);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
}

void solve(){
	int n;
	scanf("%d", &n);
	REPN(i, 1, n) {
		used[i] = 0;
	}
	// int tot_cnt = 0;
	REPN(i, 1, n) {
		if (used[i] == 1) {
			continue;
		}
		v.clear();
		while(1) {
			int cur = ask(i);
			if (used[cur]) {
				break;
			}
			used[cur] = 1;
			v.pb(cur);
		}
		REP(j, 0, SZ(v)) {
			p[v[j]] = v[(j + 1) % SZ(v)];
		}
		// tot_cnt += (SZ(v) + 1);
	}
	printf("!");
	REPN(i, 1, n) {
		printf(" %d", p[i]);
	}
	putchar('\n');
	fflush(stdout);
}

int main(){
/*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif*/
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}