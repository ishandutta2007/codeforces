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

int a[2][MAXN], n[2];

int aa[MAXN];
int ind[MAXN];

int ans;
int ans_fir, ans_sec;

void append(int arr_ind, int arr_pos, int &top) {
	aa[top] = a[arr_ind][arr_pos];
	ind[top] = (arr_ind == 0 ? arr_pos: arr_pos + n[0]);
	top++;
}

void go(int arr_ind, int &arr_pos, int &top) {
	int p = a[arr_ind][arr_pos];
	for(; arr_pos < n[arr_ind] && a[arr_ind][arr_pos] == p; arr_pos++) {
		append(arr_ind, arr_pos, top);
	}
}

void go(int fir, int sec) {
	int l[2];
	l[0] = l[1] = 0;
	int top = 0;
	go(fir, l[fir], top);
	for(int arr_ind = sec; l[0] < n[0] || l[1] < n[1]; arr_ind ^= 1) {
		go(arr_ind, l[arr_ind], top);
	}
	int cur = 0;
	REP(i, 0, n[0] + n[1]) {
		if (aa[i] != aa[i + 1]) {
			cur++;
		}
	}
	if (cur < ans) {
		ans = cur;
		ans_fir = fir;
		ans_sec = sec;
	}
}

void solve(){
	REP(i, 0, 2) {
		scanf("%d", &n[i]);
		REP(j, 0, n[i]) {
			scanf("%d", &a[i][j]);
		}
	}
	ans = INF;
	REP(i, 0, 2) {
		REP(j, 0, 2) {
			go(i, j);
		}
	}
	go(ans_fir, ans_sec);
	REP(i, 0, n[0] + n[1]) {
		printf("%d ", ind[i] + 1);
	}
	printf("\n%d\n", ans);
	REP(i, 0, n[0] + n[1]) {
		if (aa[i] != aa[i + 1]) {
			printf("%d ", i + 1);
		}
	}
}

int main(){
freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}