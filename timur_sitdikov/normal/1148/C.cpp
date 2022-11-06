#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 3e5 + 5;

int per[MAXN];
int ind[MAXN];

vector<pii> ans;

void my_swap(int i, int j) {
	if (i == j) {
		return;
	}
	ans.pb(mp(i, j));
	swap(per[i], per[j]);
	ind[per[i]] = i;
	ind[per[j]] = j;
}

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d", &per[i]);
		per[i]--;
		ind[per[i]] = i;
	}
	for(int i = n / 2; i < n; i++) {
		if (ind[i] < n / 2 && ind[i] != 0) {
			my_swap(ind[i], n - 1);
		}
		if (ind[i] != i && ind[i] >= n / 2) {
			my_swap(0, ind[i]);
		}
		if (ind[i] != i) {
			my_swap(0, i);
		}
	}
	for(int i = n / 2 - 1; i >= 0; i--) {
		if (ind[i] != i) {
			my_swap(ind[i], n - 1);
			my_swap(i, n - 1);
		}
	}
	
	/*REP(i, 0, n) {
		printf("%d ", per[i]);
	}
	putchar('\n');*/
	
	printf("%d\n", SZ(ans));
	REP(i, 0, SZ(ans)) {
		printf("%d %d\n", ans[i]._1 + 1, ans[i]._2 + 1);
	}
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}