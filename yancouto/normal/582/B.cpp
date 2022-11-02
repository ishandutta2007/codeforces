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
int a[203], c[305], t, n;
int memo[102][102][2][102];
int solve(int i, int last, bool can, int jmp) {
	if(i < 0 && jmp == 0) return 0;
	int &r = memo[i+1][last][can][jmp];
	if(r != -1) return r;
	if(jmp) r = max(r, solve(n - 1, last, can, jmp - 1));
	if(i >= 0) r = max(r, solve(i - 1, last, can, jmp));
	if(i >= 0 && a[i] <= a[last]) {
		r = max(r, 1 + solve(i - 1, i, can, jmp));
		if(can) r = max(r, 1 + solve(i - 1, i, false, jmp) + c[a[i]] * (t - min(t - 1, n) - 1));
	}
	return r;
}


int main() {
	int i;
	scanf("%d %d", &n, &t);
	//srand(n * t + n); rand(); rand();
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		//a[i] = rand() % 300;
		//printf("%d\n", a[i]);
	}
	memset(memo, -1, sizeof memo);
	for(i = 0; i < n; i++)
		c[a[i]]++;
	int mx = 0;
	for(i = 0; i < n; i++) {
		mx = max(mx, solve(i - 1, i, true, min(t - 1, n)) + 1);
		mx = max(mx, solve(i - 1, i, false, min(t - 1, n)) + 1 + c[a[i]] * (t - 1 - min(t - 1, n)));
	}
	printf("%d\n", mx);
}