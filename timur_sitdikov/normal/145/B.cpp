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

const int MAXN = 2e6 + 5;

char ans[MAXN];

void solve(){
	int a1, a2, a3, a4;
	scanf("%d%d%d%d", &a1, &a2, &a3, &a4);
	if (max(a3, a4) > min(a1, a2) || a3 + a4 + 1 > a1 + a2 || abs(a3 - a4) > 1) {
		printf("-1\n");
		return;
	}
	int top = 0;
	if (a3 - a4 == 1) {
		REP(i, 0, a3) {
			ans[top++] = '4';
			ans[top++] = '7';
		}
	} else if (a3 - a4 == -1) {
		REP(i, 0, a4) {
			ans[top++] = '7';
			ans[top++] = '4';
		}
	} else {
		if (a1 == a3) {
			ans[top++] = '7';
			REP(i, 0, a3) {
				ans[top++] = '4';
				ans[top++] = '7';
			}
		} else {
			REP(i, 0, a3) {
				ans[top++] = '4';
				ans[top++] = '7';
			}
			ans[top++] = '4';
		}
	}
	int cnt4 = 0, cnt7 = 0;
	int ind4 = -1, ind7 = -1;
	REP(i, 0, top) {
		if (ans[i] == '4') {
			cnt4++;
			if (ind4 == -1) {
				ind4 = i;
			}
		} else {
			cnt7++;
			ind7 = i;
		}
	}
	REP(i, 0, top) {
		putchar(ans[i]);
		if (i == ind4) {
			REP(j, 0, a1 - cnt4) {
				putchar('4');
			}
		}
		if (i == ind7) {
			REP(j, 0, a2 - cnt7) {
				putchar('7');
			}
		}
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