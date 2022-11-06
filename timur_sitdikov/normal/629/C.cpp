#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i, a, b) for((i) = (int)(a); (i) < (int)(b); (i)++)
#define REPN(i, a, b) for((i) = (int)(a); (i) <= (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 2e5 + 5, MAXV = 2e3 + 5;
const ll MOD = 1e9 + 7;

int c[MAXV][MAXV];
char s[MAXN];

ll get_val(int i, int j){
	if (i > MAXV || j > i || (i - j) % 2 != 0){
		return 0ll;
	}
	return (c[i][(i + j) / 2] - c[i][(i + j) / 2 + 1] + MOD) % MOD;
}

void solve(){
	int n, m, b, cur_b, i, j;
	scanf("%d%d%s", &n, &m, &s[0]);
	REP(i, 0, MAXV){
		c[i][0] = c[i][i] = 1ll;
		REP(j, 1, i){
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
		}
	}
	ll ans = 0;
	b = cur_b = 0;
	REP(i, 0, m){
		if (s[i] == '('){
			cur_b++;
		} else {
			cur_b--;
		}
		b = min(b, cur_b);
	}
	b = -b;
	REPN(i, 0, n - m){
		REPN(j, b, i){
			// cout << i << " " << j << " " << get_val(i, j) << endl;
			// cout <<	n - m - i << " " << j + cur_b << " " << get_val(n - m - i, j + cur_b) << endl;
			ans = (ans + (get_val(i, j) * get_val(n - m - i, j + cur_b))) % MOD;
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