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
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

char c[MAXN];
char col[MAXN];
char last[200];

void solve(){
	int n;
	scanf("%d%s", &n, &c[0]);
	REP(i, 0, n) {
		col[i] = 0;
	}
	int ind = -1;
	REP(i, 1, n) {
		if (c[i] < c[i - 1]) {
			ind = i;
			break;
		}
	}
	if (ind == -1) {
		REP(i, 0, n) {
			putchar('1');
		}
		putchar('\n');
		return;
	}
	last['1'] = last['2'] = '0' - 1;
	int fir = INF;
	REP(i, 0, n) {
		if (i <= ind) {
			if (c[i] <= c[ind]) {
				col[i] = '1';
			} else {
				if (fir == INF) {
					fir = c[i];
				}
				col[i] = '2';
			}
		} else {
			if (c[i] >= last['2']) {
				col[i] = '2';
			} else if (c[i] <= fir && c[i] >= last['1']) {
				col[i] = '1';
			} else  {
				printf("-\n");
				return;
			}
		}
		last[col[i]] = c[i];
	}
	col[n] = 0;
	printf("%s\n", col);
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