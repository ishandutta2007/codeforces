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
const ll MOD = 1e9 + 7;

const int MAXN = 1005;

int cnt[MAXN][MAXN];

void solve(){
	int n, w, m;
	scanf("%d%d%d", &n, &w, &m);
	
	REP(i, 0, n * m) {
		cnt[i / n][i / m]++;
	}
	
	REP(j, 0, n) {
		int v = 0;
		REP(i, 0, m) {
			if (cnt[i][j]) {
				v++;
			}
		}
		if (v > 2) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	REP(i, 0, m) {
		REP(j, 0, n) {
			if (cnt[i][j]) {
				printf("%d %.12lf ", j + 1, cnt[i][j] / (m + 0.) * w);
			}
		}
		putchar('\n');
	}
	
	/*REPN(d, m - 1, n) {
		if ((n % d) {
			continue;
		}
		REP(k, 0, n / d) {
			int offset = 1 + k * d;
			int last = 0;
			for(int i = 0, j = 0; j < m; j++) {
				int v = m;
				while(v) {
					int cur = max(m - last, v);
					cnt[j][offset + i] = cur;
					v -= cur;
					if (cur == m - last) {
						last = 0;
						i++;
					} else {
						last = cur;
					}
				}
			}
		}
		printf("YES\n");
		REP(j, 0, m) {
			REP(i, 0, n) {
				if (cnt[j][i]) {
					printf("%d %.12lf ", i + 1, cnt[j][i] / (m + 0.) * w);
				}
			}
			putchar('\n');
		}
	}
	printf("NO\n");*/
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