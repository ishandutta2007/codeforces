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

const int MAXN = 3e5 + 5;

char s[MAXN];

vi add;

vi add0;

void solve(){
	int n, k;
	scanf("%d%d%s", &n, &k, &s[1]);
	k = min(k, n);
	add.clear();
	add0.clear();
	int sum = 0;
	int last = 0;
	REPN(i, 1, n) {
		if (s[i] == 'W') {
			sum++;
			if (i > 0 && s[i - 1] == 'W') {
				sum++;
			}
			if (last != i - 1) {
				if (last == 0) {
					add0.pb(i - last - 1);
				} else {
					add.pb(i - last - 1);
				}
			}
			last = i;
		}
	}
	if (last != n) {
		add0.pb(n - last);
	}
	if (k == 0) {
		printf("%d\n", sum);
		return;
	}
	if (sum == 0) {
		printf("%d\n", 2 * k - 1);
		return;
	}
	SORT(add);
	SORT(add0);
	REP(i, 0, SZ(add)) {
		int d = min(add[i], k);
		if (d == add[i]) {
			sum += 2 * d + 1;
		} else {
			sum += 2 * d;
		}
		k -= d;
	}
	REP(i, 0, SZ(add0)) {
		int d = min(add0[i], k);
		sum += 2 * d;
		k -= d;
	}
	printf("%d\n", sum);
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