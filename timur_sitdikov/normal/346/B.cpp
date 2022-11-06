#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double DOUBLE;
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

#define x0 gray_cat_x0
#define y0 gray_cat_y0
#define x1 gray_cat_x1
#define y1 gray_cat_y1
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;

const int MAXN = 1e2 + 5;

char s1[MAXN], s2[MAXN], virus[MAXN];

int dp[MAXN][MAXN][MAXN];
pair<pii, int> prv[MAXN][MAXN][MAXN];

int pf[MAXN];

void solve(){
	scanf("%s%s%s", &s1[0], &s2[0], &virus[0]);
	int n1 = strlen(s1), n2 = strlen(s2), nv = strlen(virus);
	REP(i, 1, nv) {
		int j = pf[i - 1];
		while(j > 0 && virus[j] != virus[i]){
			j = pf[j - 1];
		}
		if (virus[j] == virus[i]){
			j++;
		}
		pf[i] = j;
	}
	REPN(i, 0, n1) {
		REPN(j, 0, n2) {
			REP(k, 0, nv) {
				dp[i][j][k] = -1;
			}
		}
	}
	dp[0][0][0] = 0;
	REPN(i, 0, n1) {
		REPN(j, 0, n2) {
			REP(k, 0, nv) {
				if (dp[i][j][k] == -1) {
					continue;
				}
				if (dp[i + 1][j][k] < dp[i][j][k]) {
					dp[i + 1][j][k] = dp[i][j][k];
					prv[i + 1][j][k] = {{i, j}, k};
				}
				if (dp[i][j + 1][k] < dp[i][j][k]) {
					dp[i][j + 1][k] = dp[i][j][k];
					prv[i][j + 1][k] = {{i, j}, k};
				}
				if (i < n1 && j < n2 && s1[i] == s2[j]) {
					int k1 = k;
					while(k1 > 0 && virus[k1] != s1[i]){
						k1 = pf[k1 - 1];
					}
					if (virus[k1] == s1[i]) {
						k1++;
					}
					if (k1 != nv && dp[i + 1][j + 1][k1] < dp[i][j][k] + 1) {
						dp[i + 1][j + 1][k1] = dp[i][j][k] + 1;
						prv[i + 1][j + 1][k1] = {{i, j}, k};
					}
				}
			}
		}
	}
	pair<pii, int> maxi = {{-1, -1}, -1};
	int mx = -1;
	REPN(i, 0, n1) {
		REPN(j, 0, n2) {
			REP(k, 0, nv) {
				if (mx < dp[i][j][k]) {
					mx = dp[i][j][k];
					maxi = {{i, j}, k};
				}
			}
		}
	}
	vector<char> ans;
	for(int i = maxi._1._1, j = maxi._1._2, k = maxi._2; i || j || k; ) {
		int i1 = prv[i][j][k]._1._1;
		int j1 = prv[i][j][k]._1._2;
		int k1 = prv[i][j][k]._2;
		if (dp[i1][j1][k1] < dp[i][j][k]) {
			ans.pb(s1[i1]);
		}
		i = i1, j = j1, k = k1;
	}
	reverse(BE(ans));
	if (SZ(ans) == 0) {
		ans.pb('0');
	}
	REP(i, 0, SZ(ans)) {
		putchar(ans[i]);
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