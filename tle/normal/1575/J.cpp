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
const int maxn = 1005;
const int maxk = 100005;
int ans[maxk], c[maxk];
int a[maxn][maxn];
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	}
	for (int i = 1; i <= k; i++) {
		int c; scanf("%d", &c);
		int x = 1, y = c;
		while (x <= n) {
			if (a[x][y] == 2) 
				x += 1;
			else if (a[x][y] == 1) {
				a[x][y] = 2;
				y += 1;
			}
			else {
				a[x][y] = 2;
				y -= 1;
			}
		}
		ans[i] = y;
	}
	for (int i = 1; i <= k; i++)
		printf("%d ", ans[i]);
    return (0-0); //<3
}