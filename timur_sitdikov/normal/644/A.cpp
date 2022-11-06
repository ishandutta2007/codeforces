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

#define REP(i, a, b) for((i) = (a); (i) < (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll INF = 1e18;
const int MAXN = 105;
const ll MOD = 1e9 + 7;

int v[MAXN][MAXN];

void solve(){
	int n, i, j, a, b;
	cin >> n >> a >> b;
	if (n > a * b){
		printf("-1\n");
		return;
	}
	REP(i, 0, a){
		if (i % 2 == 0){
			for(j = 0; j < b; j++){
				v[i][j] = n;
				n = max(n - 1, 0);
			}
		} else {
			for(j = b - 1; j >= 0; j--){
				v[i][j] = n;
				n = max(n - 1, 0);
			}
		}
	}
	REP(i, 0, a){
		REP(j, 0, b){
			printf("%d ", v[i][j]);
		}
		putchar('\n');
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