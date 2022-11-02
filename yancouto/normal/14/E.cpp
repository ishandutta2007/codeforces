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

ll memo[22][4][2][12];
int n;
ll solve(int i, int cur, bool up, int t) {
	if(t < 0) return 0;
	if(i == n - 1) return t == 0 && !up;
	ll &r = memo[i][cur][up][t];
	if(r != -1) return r;
	r = 0;
	if(i != n - 2)
		for(int v = cur + 1; v < 4; v++)
			r += solve(i + 1, v, true, t);
	if(i != 0)
		for(int v = 0; v < cur; v++)
			r += solve(i + 1, v, false, t - up);
	return r;
}

int main() {
	int t;
	scanf("%d %d", &n, &t);
	memset(memo, -1, sizeof memo);
	printf("%I64d\n", solve(0, 0, true, t) + solve(0, 1, true, t) + solve(0, 2, true, t));
}