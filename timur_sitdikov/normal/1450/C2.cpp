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
const ll MOD = 1e9 + 7;

const int MAXN = 3e2 + 5;

char g[MAXN][MAXN];

int cnt[3][2];

void solve(){
	REP(i, 0, 3) {
		REP(j, 0, 2) {
			cnt[i][j] = 0;
		}
	}
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%s", &g[i][0]);
		REP(j, 0, n) {
			if (g[i][j] == 'O') {
				cnt[(i + j) % 3][0]++;
			} else if (g[i][j] == 'X') {
				cnt[(i + j) % 3][1]++;
			}
		}
	}
	int mini = 0;
	REP(i, 1, 3) {
		if (cnt[i][0] + cnt[(i + 1) % 3][1] < cnt[mini][0] + cnt[(mini + 1) % 3][1]) {
			mini = i;
		}
	}
	REP(i, 0, n) {
		REP(j, 0, n) {
			if ((i + j) % 3 == mini && g[i][j] == 'O') {
				g[i][j] = 'X';
			} else if ((i + j) % 3 == (mini + 1) % 3 && g[i][j] == 'X') {
				g[i][j] = 'O';
			}
		}
		printf("%s\n", g[i]);
	}
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}