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
const int MAXN = 2e6 + 55;
const ll MOD = 1e9 + 7;

char c[MAXN];

ll dp[MAXN];
int ind[200];

void solve(){
	int n, k, m, i, j;
	scanf("%d%d%s", &n, &k, &c[1]);
	m = strlen(&c[1]);
	for(i = 1; i <= m; i++){
		dp[i] = 1ll;
		for(j = 'a'; j < 'a' + k; j++){
			dp[i] = (dp[i] + dp[ind[j]]) % MOD;
		}
		ind[c[i]] = i;
	}
	for(i = m + 1; i <= m + n; i++){
		ll mn = INF, mini = 0;
		dp[i] = 1ll;
		for(j = 'a'; j < 'a' + k; j++){
			dp[i] = (dp[i] + dp[ind[j]]) % MOD;
			if (ind[j] < mn){
				mn = ind[j];
				mini = j;
			}
		}
		ind[mini] = i;
	}
	ll ans = 1ll;
	for(j = 'a'; j < 'a' + k; j++){
		ans = (ans + dp[ind[j]]) % MOD;
	}
	cout << ans<< endl;
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}