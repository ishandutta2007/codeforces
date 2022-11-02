#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ull x) { return x % modn; }

ll cmb[4009][4009];
ll comb(int n, int p) {
	if(n == p) return 1;
	if(p == 0) return 1;
	ll &r = cmb[n][p];
	if(r != -1) return r;
	return r = mod(comb(n - 1, p) + comb(n - 1, p - 1));
}

ll q(int);
ll g(int);

ll memos[4009];
ll s(int n) {
	if(n == 0) return 0;
	ll &r = memos[n];
	if(r != -1) return r;
	r = q(n - 1);
	for(int i = 0; i <= (n - 1); i++)
		r = mod(r + mod(comb(n - 1, i) * s(n - 1 - i)));
	return r;
}

ll memoq[4009];
ll q(int n) {
	return mod(s(n) + g(n));
}

ll memog[4009];
ll g(int n) {
	if(n == 0) return 1;
	ll &r = memog[n];
	if(r != -1) return r;
	r = 0;	
	for(int i = 0; i <= (n - 1); i++)
		r = mod(r + mod(comb(n - 1, i) * g(n - 1 - i)));
	return r;
}

int main() {
	int n;
	scanf("%d", &n);
	memset(memos, -1, sizeof memos);
	memset(memoq, -1, sizeof memoq);
	memset(memog, -1, sizeof memog);
	memset(cmb, -1, sizeof cmb);
	printf("%d\n", (int) s(n));
	return 0;
}