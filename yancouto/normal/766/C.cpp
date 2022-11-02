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

int n;

const int N = 1123;

int a[30];
char s[N];
tuple<ll, int, int> memo[N];
tuple<ll, int, int> solve(int i) {
	if(i == n) return make_tuple(1ll, 0, 0);
	if(get<0>(memo[i]) != -1) return memo[i];
	ll a; int b; int c;
	a = 0; b = 0; c = INT_MAX;
	int mx = INT_MAX;
	for(int j = i; j < n; j++) {
		mx = min(mx, ::a[s[j] - 'a']);
		if(j - i + 1 > mx) break;
		ll a2; int b2; int c2;
		tie(a2, b2, c2) = solve(j + 1);
		a = mod(a + a2);
		b = max(b2, max(b, j - i + 1));
		c = min(c, c2 + 1);
	}
	return memo[i] = make_tuple(a, b, c);
}

int main() {
	int i;
	scanf("%d", &n);
	scanf("%s", s);
	for(i = 0; i < 26; i++) scanf("%d", &a[i]);
	ll a; int b; int c;
	memset(memo, -1, sizeof memo);
	tie(a, b, c) = solve(0);
	printf("%d\n%d\n%d\n", (int) a, b, c);
}