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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;

int a[MAXN];

void solve(){
	int n, i;
	scanf("%d", &n);
	REP(i, 0, n){
		scanf("%d", &a[i]);
	}
	ll ans = 0ll, cur = 0ll;
	REP(i, 0, n){
		ans = (ans + a[i] - 1ll) % MOD;
		if (i != 0){
			ans = (ans + cur * (min(a[i], a[i - 1]) - 1)) % MOD;
		}
		if (i != n - 1){
			int lim1 = min(a[i], a[i + 1]);
			int lim = lim1;
			if (i != 0){
				lim = min(lim, a[i - 1]);
			}
			cur = (cur * (lim - 1) + lim1 - 1) % MOD;
		}
	}
	cout << ans << endl;
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}