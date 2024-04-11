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

int a[30009];
int memo[30009][1000];
int L;
int solve(int i, int l) {
	if(l == 0) return 0;
	if(i > 30000) return 0;
	if(memo[i][l - L + 500]) return memo[i][l - L + 500] - 1;
	int &r = memo[i][l - L + 500];
	r = max(solve(i + l, l),  solve(i + l + 1, l + 1));
	r = max(r, solve(i + l - 1, l - 1));
	r = r + a[i] + 1;
	return r - 1;
}

int main() {
	int i, j, n, d, x;
	scanf("%d %d", &n, &d);
	L = d;
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		a[x]++;
	}
	printf("%d\n", solve(d, d));
}