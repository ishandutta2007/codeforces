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
const ll m = 1000000006;
inline ll md(ll x) { return x % m; }

ll fexp(ll n, ll p) {
	ll r = 1;
	for(; p; p >>= 1, n = mod(n * n))
		if(p & 1)
			r = mod(r * n);
	return r;
}

ll d[10], sz[10];
string s[100009];
char s1[100009], s2[100009];
char c[100009];
int main() {
	int i, n;
	scanf("%s %d", s1, &n);
	for(i = 0; i < n; i++) {
		scanf(" %c", &c[i]);
		fgets(s2, 100009, stdin);
		s[i] = s2;
	}
	for(i = 0; i < 10; i++) d[i] = i, sz[i] = 1;
	for(i = n - 1; i >= 0; i--) {
		ll p = 1; ll v = 0, s = 0;
		for(char c : ::s[i]) {
			if(!isdigit(c)) continue;
			v = mod(v * fexp(10, sz[c - '0']) + d[c - '0']);
			s = md(s + sz[c - '0']);
		}
		d[c[i] - '0'] = v;
		sz[c[i] - '0'] = s;
	}
	ll v = 0;
	for(i = 0; s1[i]; i++)
		v = mod(v * fexp(10, sz[s1[i] - '0']) + d[s1[i] - '0']);
	printf("%d\n", (int) v);
}