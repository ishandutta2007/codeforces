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

int a[200], n;
int memo[200][2][2];
int solve(int i, bool sp, bool cn) {
	if(i == n) return 0;
	int &r = memo[i][sp][cn];
	if(r != -1) return r;
	r = 1 + solve(i + 1, true, true);
	if(sp && (a[i] & 2)) r = min(r, solve(i + 1, false, true));
	if(cn && (a[i] & 1)) r = min(r, solve(i + 1, true, false));
	if(sp && cn && a[i] == 3) r = min(r, solve(i + 1, false, false));
	return r;
}

int main() {
	memset(memo, -1, sizeof memo);
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d\n", solve(0, true, true));
}