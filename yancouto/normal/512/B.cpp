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

int mdc(int a, int b) {
	if(b == 0) return a;
	return mdc(b, a % b);
}

const int N = 310;
int n, l[N], c[N];
map<int, int> memo[302];
int solve(int i, int x) {
	if(x == 1) return 0;
	if(i == n) return 100000000;
	if(memo[i].count(x)) return memo[i][x];
	return memo[i][x] = min(solve(i + 1, mdc(x, l[i])) + c[i], solve(i + 1, x));
}

int main() {
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &l[i]);
	for(i = 0; i < n; i++)
		scanf("%d", &c[i]);
	int m = 0;
	for(i = 0; i < n; i++)
		m = mdc(m, l[i]);
	if(m != 1) { puts("-1"); return 0; }
	printf("%d\n", solve(0, 0));
}