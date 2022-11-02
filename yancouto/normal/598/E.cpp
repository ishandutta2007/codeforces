#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int memo[32][32][52];
int solve(int n, int m, int k) {
	if(k == 0) return 0;
	if(n * m == k) return 0;
	if(n * m < k) return 100000000;
	int &r = memo[n][m][k];
	if(r != -1) return r;
	r = 100000000;
	for(int i = 1; i < n; i++)
		for(int j = 0; j <= k; j++)
			r = min(r, m * m + solve(i, m, j) + solve(n - i, m, k - j));
	for(int i = 1; i < m; i++)
		for(int j = 0; j <= k; j++)
			r = min(r, n * n + solve(n, i, j) + solve(n, m - i, k - j));
	return r;
}

int main() {
	int n, m, k;
	memset(memo, -1, sizeof memo);
	for_tests(t, tt) {
		scanf("%d %d %d", &n, &m, &k);
		printf("%d\n", solve(n, m, k));
	}
}