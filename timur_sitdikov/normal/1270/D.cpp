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
const ll LL_INF = 1e17 + 10;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

int mask[MAXN];
int n, k;
int pos, val, pos1, pos2, val1, val2;

void make_query() {
	printf("?");
	REPN(i, 1, n) {
		if (mask[i]) {
			printf(" %d", i);
		}
	}
	putchar('\n');
	fflush(stdout);
	scanf("%d%d", &pos, &val);
}

void output(int ans) {
	printf("! %d\n", ans);
	fflush(stdout);
}

void solve(){
	scanf("%d%d", &n, &k);
	if (k == 1) {
		output(1);
		return;
	}
	REPN(i, 1, k) {
		mask[i] = 1;
	}
	make_query();
	pos1 = pos;
	val1 = val;
	
	mask[pos] = 0;
	mask[k + 1] = 1;
	make_query();
	pos2 = pos;
	val2 = val;
	
	mask[pos1] = 1;
	int cnt_le = 1;
	REPN(i, 1, k + 1) {
		if (i == pos1 || i == pos2) {
			continue;
		}
		mask[i] = 0;
		make_query();
		if (val1 < val2) {
			if (pos == pos2) {
				cnt_le++;
			}
		} else {
			if (pos == pos1) {
				cnt_le++;
			}
		}
		mask[i] = 1;
	}
	output(cnt_le);
}   

int main(){
/*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif*/
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}