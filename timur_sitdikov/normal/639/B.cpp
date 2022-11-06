#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<long double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for((i) = (a); (i) < (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

void solve(){
	int n, d, h, i, j;
	cin >> n >> d >> h;
	if (d == 1){
		if (n > 2){
			printf("-1\n");
			return;
		}
		printf("1 2\n");
		return;
	}
	if (d > h + h){
		printf("-1\n");
		return;
	}
	for(i = 1; i <= h; i++){
		printf("%d %d\n", i, i + 1);
	}
	if (d != h){
		printf("1 %d\n", h + 2);
		for(j = h + 2; j <= d; j++){
			printf("%d %d\n", j, j + 1);
		}
		for(j = d + 2; j <= n; j++){
			printf("1 %d\n", j);
		}
	} else {
		for(j = d + 2; j <= n; j++){
			printf("2 %d\n", j);
		}
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