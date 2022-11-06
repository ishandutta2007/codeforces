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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9 + 5;
const int MAXN = 5e5 + 5;
const ll MOD = 1e9 + 7;

int v[MAXN];

void read_point(point &a){
	double x, y;
	scanf("%lf%lf", &x, &y);
	a = point(x, y);
}

void solve(){
	int n, k;
	scanf("%d%d", &n, &k);
	REP(i, 0, n){
		scanf("%d", &v[i]);
	}
	int l = 0, r = INF;
	for(; l + 1 < r; ){
		int mid = (l + r) >> 1;
		int sum = k;
		REP(i, 0, n){
			sum -= max(0, mid - v[i]);
			if (sum < 0){
				break;
			}
		}
		if (sum >= 0){
			l = mid;
		} else {
			r = mid;
		}
	}
	int dd = l;
	l = 0, r = INF;
	for(; l + 1 < r; ){
		int mid = (l + r) >> 1;
		int sum = k;
		REP(i, 0, n){
			sum -= max(0, v[i] - mid);
			if (sum < 0){
				break;
			}
		}
		if (sum >= 0){
			r = mid;
		} else {
			l = mid;
		}
	}
	int uu = r;
	int ans = max(0, uu - dd);
	int sum = 0;
	REP(i, 0, n){
		sum = (sum + v[i]) % n;
	}
	if (sum){
		ans = max(ans, 1);
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