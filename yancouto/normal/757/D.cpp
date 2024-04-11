#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int memo2[1 << 20];
inline int miss(int bm) {
	if(memo2[bm] != -1) return memo2[bm];
	int mx = 32 - __builtin_clz(bm);
	return memo2[bm] = mx - __builtin_popcount(bm);
}

char s[100]; int a[100];

int n;
int nx[100];
int memo[1 << 20][75];
bitset<76> seen[1 << 20];

ll solve(int i, int bm) {
	if(i == n) return miss(bm) == 0;
	if(seen[bm][i]) return memo[bm][i];
	seen[bm][i] = 1;
	if(bm && miss(bm) > n - i) return memo[bm][i] = 0;
	ll r = bm && miss(bm) == 0;
	int cur = 0;
	for(int j = nx[i]; j < n; j++) {
		cur = (cur << 1) | a[j];
		if(cur > 20) return memo[bm][i] = r;
		r = r + solve(j + 1, bm | (1 << (cur - 1)));
		if(r > modn) r -= modn;
	}
	return memo[bm][i] = r;
}


int main() {
	int i, j;
	scanf("%d", &n);
	scanf("%s", s);
	memset(memo2, -1, sizeof memo2);
	for(i = 0; s[i]; i++) a[i] = s[i] - '0';
	nx[n] = n;
	for(i = n - 1; i >= 0; i--)
		if(a[i]) nx[i] = i;
		else nx[i] = nx[i + 1];
	ll tot = 0;
	for(i = 0; i < n; i++)
		tot = mod(tot + solve(i, 0));
	printf("%lld\n", tot);
}