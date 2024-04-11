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
const int N = 1000009;
int f[N], p[N]; bool seen[N];
vector<int> c[N];
int aux[N];

void shift_odd(int sz, int g) {
	for(int i = 0; i < sz; i++) {
		aux[(2 * i) % sz] = g;
		g = f[g];
	}
	for(int i = 0; i < sz - 1; i++)
		p[aux[i]] = aux[i + 1];
	p[aux[sz - 1]] = aux[0];
}

void join_even(int sz, int a, int b) {
	for(int i = 0; i < sz; i++) {
		p[a] = b;
		p[b] = f[a];
		a = f[a];
		b = f[b];
	}
}

int main() {
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &f[i]);
		f[i]--;
	}
	for(i = 0; i < n; i++) {
		if(seen[i]) continue;
		int g = i, sz = 0;
		while(!seen[g]) {
			sz++;
			seen[g] = true;
			g = f[g];
		}
		c[sz].pb(i);
	}
	for(i = 1; i <= n; i++) {
		if(c[i].empty()) continue;
		if(!(i & 1) && (c[i].size() & 1)) { puts("-1"); return 0; }
		if(i & 1) for(int g : c[i]) shift_odd(i, g);
		else
			for(int j = 0; j < c[i].size(); j += 2)
				join_even(i, c[i][j], c[i][j + 1]);
	}

	for(i = 0; i < n; i++)
		printf("%d ", p[i] + 1);
	putchar('\n');
}