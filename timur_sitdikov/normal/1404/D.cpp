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

const int MAXN = 1e6 + 5;

void process_even(int n) {
	printf("First\n");
	REPN(i, 1, n) {
		printf("%d ", i);
	}
	REPN(i, 1, n) {
		printf("%d ", i);
	}
	putchar('\n');
	fflush(stdout);
}

vi vv[MAXN];
int v[MAXN];

int used[MAXN];
int col[MAXN];
ll sum[3];

void process_odd(int n) {
	printf("Second\n");
	fflush(stdout);
	REPN(i, 1, 2 * n) {
		int a;
		scanf("%d", &a);
		vv[a].pb(i);
	}
	REPN(i, 1, n) {
		int a = vv[i][0], b = vv[i][1];
		v[a] = b, v[b] = a;
	}
	REPN(i, 1, n) {
		if (!used[i]) {
			for(int j = i; !used[j]; ) {
				used[j] = 1;
				used[v[j]] = 1;
				col[j] = 1;
				col[v[j]] = 2;
				int nxt = v[j];
				if (nxt > n) {
					nxt -= n;
				} else {
					nxt += n;
				}
				j = nxt;
			}
		}
	}
	REPN(i, 1, 2 * n) {
		sum[col[i]] += i;
	}
	int ind = 1;
	if (sum[2] % 2 == 0) {
		ind = 2;
	}
	/*REPN(i, 1, 2 * n) {
		printf("%d ", col[i]);
	}
	putchar('\n');*/
	REPN(i, 1, 2 * n) {
		if (col[i] == ind) {
			printf("%d ", i);
		}
	}
	putchar('\n');
	fflush(stdout);
}

void solve(){
	int n;	
	scanf("%d", &n);
	if (n % 2 == 0) {
		process_even(n);
	} else {
		process_odd(n);
	}
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