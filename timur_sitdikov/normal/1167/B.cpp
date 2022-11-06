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

const int MAXN = 2e5 + 5;

int v[6] = {4, 8, 15, 16, 23, 42};

int ind[4][2] = {{0, 1}, {2, 3}, {0, 4}, {2, 5}};

int per[6];

void solve(){
	int n;
	int p[4];
	REP(i, 0, 4) {
		printf("? %d %d\n", ind[i][0] + 1, ind[i][1] + 1);
		fflush(stdout);
		scanf("%d", &p[i]);
	}
	REP(i, 0, 6){
		per[i] = i;
	}
	while(1) {
		int fl = 0;
		REP(i, 0, 4) {
			if (v[per[ind[i][0]]] * v[per[ind[i][1]]] != p[i]) {
				fl = 1;
				break;
			}
		}
		if (!fl) {
			printf("!");
			REP(i, 0, 6) {
				printf(" %d", v[per[i]]);
			}
			putchar('\n');
			fflush(stdout);
			return;
		}
		next_permutation(per, per + 6);
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