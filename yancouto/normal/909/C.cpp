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
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;

char s[5009];
int memo[5009][5009][2];
ll solve(int i, int id, bool can) {
	if(i == n) return 1;
	int &r = memo[i][id][can];
	if(r != -1) return r;
	r = 0;
	if(id > 0 && can) r = solve(i, id - 1, true);
	if(s[i] == 's') r = mod(r + solve(i + 1, id, true));
	else r = mod(r + solve(i + 1, id + 1, false));
	return r;
}

int main() {
	memset(memo, -1, sizeof memo);
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf(" %c", &s[i]);
	printf("%lld\n", solve(0, 0, true));
}