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
const int N = 5123;
int memo[2][N];
ll solve(int left, int i) {
	if(i == n) return 0;
	if(n == 1) return 1;
	return memo[left & 1][i];
}

char s[N];
int nx[26][N];

int main() {
	int i, j, k;
	scanf("%d", &n);
	scanf("%s", s);
	for(j = 0; j < 26; j++) {
		nx[j][n] = n;
		for(i = n - 1; i >= 0; i--)
			if(s[i] == 'a' + j) nx[j][i] = i;
			else nx[j][i] = nx[j][i + 1];
	}
	for(i = 0; i < n; i++) memo[1][i] = 1;
	for(i = 2; i <= n; i++)
		for(j = 0; j < n; j++) {
			ll r = solve(i - 1, j);
			for(k = 0; k < 26; k++)
				if(k + 'a' != s[j])
					r = r + solve(i - 1, nx[k][j]);
			memo[i & 1][j] = mod(r);
		}
	ll ans = 0;
	for(k = 0; k < 26; k++)
		ans = ans + solve(n, nx[k][0]);
	printf("%d\n", (int) mod(ans));
}