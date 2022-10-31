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
const int N = 212345;

int cn, cc, cd, li, ns, si, en = 1;
int es[N];
string s[N];
struct edge {
	int a, b;
	int n, si;
	int operator[](int i) { return s[si][i + a]; }
	inline int len() { return (b == N? es[si] : b) - a + 1; }
};

edge tr[N][27];
int p[N];
map<int, int> st[N];
int suf[N];

void add() {
	int &e = es[si];
	string &ss = s[si];
	e++;
	for(; li <= e; li++) {
		if(ns && cd == 0) suf[ns] = cn, ns = 0;
		if(cd? tr[cn][cc][cd] == ss[e] : tr[cn][ss[e]].n) {
			if(cd++ == 0) cc = ss[e];
			if(cd == tr[cn][cc].len()) cn = tr[cn][cc].n, cd = 0;
			break;
		}
		if(cd) {
			if(ns) suf[ns] = en;
			edge &ed = tr[cn][cc];
			char w = ed[cd];
			tr[en][w] = ed;
			tr[en][w].a += cd;
			p[ed.n] = en;
			p[en + 1] = en;
			p[en] = cn;
			tr[en][ss[e]] = edge{e, N, en + 1, si};
			ns = en;
			ed.b = ed.a + cd - 1;
			ed.n = en++; en++;
			int g = cn? e - cd : li + 1;
			cn = suf[cn];
			while(tr[cn][cc = ss[g]].n && g + tr[cn][ss[g]].len() <= e) {
				g += tr[cn][cc].len();
				cn = tr[cn][cc].n;
			}
			cd = e - g;
		} else {
			p[en] = cn;
			tr[cn][ss[e]] = edge{e, N, en++, si};
			cn = suf[cn];
		}
	}
}

int k;
ll all[N];
void dfs(int u, ll ct) {
	int x = 0;
	for(int i = 0; i < 27; i++) {
		if(!tr[u][i].n) continue;
		x++;
		edge &e = tr[u][i];
		dfs(e.n, e.len());
		if(st[e.n].size() > st[u].size()) st[e.n].swap(st[u]);
		for(pii it : st[e.n]) st[u][it.fst] += it.snd;
		st[e.n].clear();
	}
	if(st[u].size() >= k) {
		for(pii e : st[u])
			all[e.fst] += ll(ct - !x) * ll(e.snd);
	}
}

void proc(string &s, int si) {
	cn = cd = cc = 0;
	for(char c : s) {
		if(cd++ == 0) cc = c;
		if(cd == tr[cn][cc].len()) cn = tr[cn][cc].n, cd = 0;
	}
	st[cn][si]++;
	for(int i = 1; i < s.size(); i++) {
		cn = p[cn];
		int g = cn? s.size() - tr[cn][cc].len() : i;
		cn = suf[cn];
		while(g != s.size()) {
			cc = s[g];
			g += tr[cn][cc].len();
			cn = tr[cn][cc].n;
		}
		st[cn][si]++;
	}
}

char ss[N];
int main() {
	int i, j, n;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++) {
		si = i;
		es[i] = -1; cn = cc = cd = li = 0;
		scanf("%s", ss);
		s[i] = ss;
		s[i] += 'a' + 26;
		for(j = 0; j < s[i].size(); j++) { s[i][j] = s[i][j] - 'a'; add(); }
	}
	for(i = 0; i < n; i++) proc(s[i], i);
	dfs(0, 0);
	for(i = 0; i < n; i++) printf("%I64d ", all[i]);
	putchar('\n');
}