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

int n, m;
int nl, nr;
char s[100009];
ll memo[2003][2][2009];
ll solve(int i, bool left, int ct) {
	if(ct > 2000) return 0;
	ll &r = memo[i][left][ct + 2002];
	if(r != -1) return r;
	r = 0;
	if(left && ct >= nl) r = solve(i, false, ct - nl + nr);
	if(i == n - m) return r = mod(r + (!left && ct == 0));
	if(ct) r += solve(i + 1, left, ct - 1);
	r += solve(i + 1, left, ct + 1);
	return r = mod(r);
}

int main() {
	int i;
	memset(memo, -1, sizeof memo);
	scanf("%d %d", &n, &m);
	scanf("%s", s);
	int ct = 0; nl = 0, nr = 0;
	for(i = 0; i < m; i++) {
		if(s[i] == ')') ct--;
		else ct++;
		if(ct < 0) nl = max(nl, -ct);
	}
	ct = 0;
	for(i = m - 1; i >= 0; i--) {
		if(s[i] == '(') ct--;
		else ct++;
		if(ct < 0) nr = max(nr, -ct);
	}
	if(nl > 2000 || nr > 2000) { puts("0"); return 0; }
	printf("%d\n", (int) solve(0, true, 0));
}