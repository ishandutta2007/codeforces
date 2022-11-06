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

const int MAXN = 2e5 + 5, MAXD = 105;

int v[MAXN];
int cnt[MAXD];
int dif_ind[2 * MAXN];

int process(int n, int a, int b) {
	if (a == b) {
		return 0;
	}
	int ans = 0;
	int *_dif_ind = dif_ind + n;
	REPN(i, -n, n) {
		_dif_ind[i] = -1;
	}
	_dif_ind[0] = 0;
	int balance = 0;
	REPN(i, 1, n) {
		if (v[i] == a) {
			balance++;
		} else if (v[i] == b) {
			balance--;
		}
		if (_dif_ind[balance] == -1) {
			_dif_ind[balance] = i;
		} else {
			ans = max(ans, i - _dif_ind[balance]);
		}
	}
	return ans;
}

void solve(){
	int n;
	scanf("%d", &n);
	int maxi = 0;
	REPN(i, 1, n) {
		scanf("%d", &v[i]);
		cnt[v[i]]++;
		if (cnt[v[i]] > cnt[maxi]) {
			maxi = v[i];
		}
	}
	int ans = 0;
	REP(i, 0, MAXD) {
		ans = max(ans, process(n, maxi, i));
	}
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