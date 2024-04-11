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

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 1e5 + 5;

int n;
int m;
int v[MAXN];

bool check(double val){
	double start = m + val;
	REP(i, 0, 2 * n){
		start -= start / v[i];
		if (start < m - EPS) {
			return false;
		}
	}
	return true;
}

void solve(){
	scanf("%d%d", &n, &m);
	REP(i, 0, n){
		scanf("%d", &v[2 * i]);
	}
	REP(i, 0, n){
		scanf("%d", &v[(2 * n + 2 * i - 1) % (2 * n)]);
	}
	
	REP(i, 0, 2 * n){
		if (v[i] == 1) {
			printf("-1\n");
			return;
		}
	}
	
	double ans = m;
	for(int i = 2 * n - 1; i >= 0; i--){
		ans = ans * v[i] / (v[i] - 1.0);
	}
	printf("%.12lf\n", ans - m);
	/*double l = 0.0, r = 1e9 + 10;
	for(int it = 0; it < 200; it++){
		double mid = (l + r) / 2.0;
		if (check(mid)){
			r = mid;
		} else {
			l = mid;
		}
	}
	if (r > 1e9 + 1){
		printf("-1\n");
	} else {
		printf("%.12lf\n", r);
	}*/
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