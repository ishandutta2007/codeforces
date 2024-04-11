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
const int N = 509;
int c[N];

int memo[N][N];
int solve(int l, int r) {
	if(r <= l) return 1;
	int &g = memo[l][r];
	if(g != -1) return g;
	g = 1000;
	if(c[l] == c[r]) g = solve(l + 1, r - 1);
	for(int i = l; i < r; i++)
		g = min(g, solve(l, i) + solve(i + 1, r));
	for(int i = r; i > l; i--)
		g = min(g, solve(i, r) + solve(l, i - 1));
	return g;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	memset(memo, -1, sizeof memo);
	printf("%d\n", solve(0, n - 1));
}