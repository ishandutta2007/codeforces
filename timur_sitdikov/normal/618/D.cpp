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
const int INF = 1e9;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

vi g[MAXN];

int used[MAXN];

int dp[MAXN], good[MAXN];

void dfs(int s){
	int i, to, cnt1, cnt2;
	used[s] = 1;
	if (SZ(g[s]) == 1){
		// cnt[s] = 1;
		good[s] = 1;
		return;
	}
	cnt1 = cnt2 = 0;
	REP(i, 0, SZ(g[s])){
		to = g[s][i];
		if (!used[to]){
			dfs(to);
			cnt1++;
			if (good[to]){
				cnt2++;
			}
			dp[s] += dp[to];
			/*dfs(to);
			cnt[s] ^= cnt[to];
			dp[s] += dp[to] + 1;
			if (cnt[to]){
				cnt1++;
				if (good[to]){
					cnt2++;
				}
			}*/
		}
	}
	dp[s] += cnt1;
	if (cnt2 >= 2){
		dp[s] -= 2;
	} else if (cnt2 == 1){
		dp[s] -= 1;
		good[s] = 1;
	} else {
		good[s] = 1;
	}
	/*dp[s]--;
	if (cnt2 >= 2){
		dp[s]--;
	} else if (cnt2 > 0){
		good[s] = 1;
	}*/
}

void solve(){
	int n, i, a, b;
	ll x, y, ans;
	scanf("%d", &n);
	cin >> x >> y;
	REP(i, 0, n - 1){
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	if (n == 2){
		cout << x << endl;
		return;
	}
	if (x == y){
		cout << x * (n - 1) << endl;
		return;
	}
	if (x > y){
		int fl = 0;
		for(i = 1; i <= n; i++){
			if (SZ(g[i]) == n - 1){
				fl = 1;
			}
		}
		if (fl){
			ans = (n - 2) * y + x;
		} else {
			ans = (n - 1) * y;
		}
		cout << ans << endl;
		return;
	}
	for(i = 1; i <= n; i++){
		if (SZ(g[i]) > 1){
			dfs(i);
			ans = dp[i] * y + (n - 1 - dp[i]) * x;
			cout << ans << endl;
			return;
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