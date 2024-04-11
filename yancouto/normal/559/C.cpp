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
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

ull fexp(ull x, ull p) {
	ull resp = 1;
	for(ull i = 1; i <= p; i <<= 1) {
		if(i & p) resp = mod(resp * x);
		x = mod(x * x);
	}
	return resp;
}
ull fat[450009];

ull comb(ull p, ull n) {
	ull r = mod(fat[n] * fexp(mod(fat[p] * fat[n - p]), modn - 2));
	return r;
}

void pre() {
	fat[0] = 1ull;
	for(ull i = 1; i < 450009ull; i++)
		fat[i] = mod(i * fat[i - 1]);
}

struct st {
	int r, c;
	ull le, ri;
	st() {}
	st(int a, int b, ull aa, ull bb) : r(a), c(b), le(aa), ri(bb) {}
} s[2002];
int degin[2002];

vector<int> sof;
vector<int> adj[2003];
int seen[2003];
void dfs(int u) {
	if(seen[u]) return;
	seen[u] = 1;
	//if(!sof.empty()) {
	//	int v = sof.back();
	//	if(!seen[u][v]) {
	//		seen[u][v] = 1;
	//		s[u].le = mod(s[u].le + modn - mod(s[v].le * comb(s[u].r - s[v].r, s[u].r - s[v].r + s[u].c - s[v].c)));
	//	}
	//}
	for(int v : adj[u])
		dfs(v);
	sof.pb(u);
}

vector<int> adj2[2003];
int main() {
	pre();
	int h, w, n, i, r, c, j;
	scanf("%d %d %d", &h, &w, &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &r, &c);
		s[i] = st(r, c, comb(r-1, r + c-2), comb(h - r, (h - r) + (w - c)));
	}
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			if(i == j) continue;
			if(s[j].r >= s[i].r && s[j].c >= s[i].c) { adj[i].pb(j); adj2[j].pb(i); }
		}
	for(i = 0; i < n; i++)
		for(int v : adj[i])
			degin[v]++;
	for(i = 0; i < n; i++)
		dfs(i);
	reverse(sof.begin(), sof.end());
	for(int u : sof)
		for(int v : adj2[u]) {
			s[u].le = mod(s[u].le + modn - mod(s[v].le * comb(s[u].r - s[v].r, s[u].r - s[v].r + s[u].c - s[v].c)));
		}
	ull totw = 0;
	for(i = 0; i < n; i++) {
		totw = mod(totw + mod(s[i].le * s[i].ri));
	}
	totw = mod(comb(h-1, h + w-2) + modn - totw);
	printf("%d\n", (int) totw);
}