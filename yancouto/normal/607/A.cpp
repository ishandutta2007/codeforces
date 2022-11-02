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
const int N = 100009;
int a[N], b[N], p[N];

int memo[N];
int solve(int i) {
	if(memo[i] != -1) return memo[i];
	if(a[p[i]] - a[p[0]] <= b[p[i]]) return memo[i] = i - 0;
	int l = 0, r = i - 1;
	while(l < r) {
		int m = (l + r + 1) / 2;
		if(a[p[i]] - a[p[m]] <= b[p[i]]) r = m - 1;
		else l = m;
	}
	return memo[i] = (i - l - 1) + solve(l);
}

int main() {
	memset(memo, -1, sizeof memo);
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d %d", &a[i], &b[i]), p[i] = i;
	sort(p, p + n, [](int i, int j) { return a[i] < a[j]; });
	int mn = INT_MAX;
	for(i = n - 1; i >= 0; i--)
		mn = min(mn, (n - 1) - i + solve(i));
	printf("%d\n", mn);
}