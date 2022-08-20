//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 505;
char a[maxn], b[maxn];
int dp[maxn][maxn][maxn]; // from i, current at j, exact k
int to[maxn][2];
char c[maxn];
int main() {
	int n, m;
	cin >> n >> m;
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	for (int i = 0; i <= m; i++) {
		for (int s = 0; s < 2; s++) {
			memcpy(c, b, sizeof(c));
			c[i + 1] = '0' + s;
			for (int u = i + 1; u >= 0; u--) {
				int flag = 1;
				// b : 1 ~ u 
				//c : i + 2 - u ~ i + 1
				for (int m = 1; m <= u; m++) 
					if (c[i + 1 - u + m] != b[m]) flag = 0;
				if (flag) {
					to[i][s] = u;
					break;
				}
			}
		}
	}
	for (int i = n + 1; i >= 1; i--)
		for (int j = 0; j <= m; j++)
			for (int s = 0; s <= n - m + 1; s++) {
				if (i == n + 1) {
					if (s == 0) dp[i][j][s] = 0;
					else dp[i][j][s] = 1e9;
				}
				else {
					dp[i][j][s] = 1e9;
					for (int l = 0; l < 2; l++) { 
						int ccos = 1;
						if (a[i] == l + '0') ccos = 0;
						int ns = s, pl = to[j][l];
						if (pl == m) ns -= 1;
						if (ns >= 0) chkmin(dp[i][j][s], ccos + dp[i + 1][pl][ns]);
					}
				}
			}
	for (int k = 0; k <= n - m + 1; k++) {
		int ans = dp[1][0][k];
		if (ans > maxn) ans = -1;
		printf("%d ", ans);
	}
    return (0-0); //<3
}