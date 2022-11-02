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

ll memo[302][100009];
ll ab[302]; int a[302], nx[302];
int n;
ll solve(int i, int left) {
	if(left < 0) return 0;
	if(i == n) return left == 0;
	ll &r = memo[i][left];
	if(r != -1) return r;
	r = mod(solve(i + 1, left) + solve(i, left - ab[i]));
	return r;
}

int main() {
	int i, j, q, t, b, c;
	scanf("%d %d %d", &n, &q, &t);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(i = 0; i < q; i++) {
		scanf("%d %d", &b, &c); b--; c--;
		nx[b] = c + 1;
	}
	for(i = 0; i < n; i++) {
		int cur = i;
		ab[i] += a[i];
		for(j = 0; j < 2*n; j++) {
			cur = nx[cur] - 1;
			if(cur == -1) break;
			t -= a[i];
			ab[cur] += a[i];
		}
		if(j == 2*n || t < 0) { puts("0"); return 0; }
	}
	memset(memo, -1, sizeof memo);
	printf("%d\n", (int) solve(0, t));
}