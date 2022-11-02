#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n, m;
char s[1123], t[1123];
int memo[1009][1009][12][2];
int solve(int i, int j, int k, bool on) {
	if(i == n || j == m) return k? -100000 : 0;
	int &r = memo[i][j][k][on];
	if(r != -1) return r;
	r = 0;
	if(on && s[i] == t[j]) r = max(r, 1 + solve(i + 1, j + 1, k, true));
	if(s[i] == t[j] && k) r = max(r, 1 + solve(i + 1, j + 1, k - 1, true));
	r = max(r, solve(i + 1, j, k, false));
	r = max(r, solve(i, j + 1, k, false));
	return r;
}

int main() {
	int i, j, k;
	scanf("%d %d %d", &n, &m, &k);
	scanf("%s %s", s, t);
	memset(memo, -1, sizeof memo);
	printf("%d\n", solve(0, 0, k, false));
}