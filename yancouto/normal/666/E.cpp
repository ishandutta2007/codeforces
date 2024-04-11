#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif

const int NS = 112345;
const int N = 1123456;
const int MX = 512345;

int cn, cd, ns, en = 1;
string S[NS];
struct edge {
	int a, b;
	int v, si;
	inline int len() { return b - a + 1; }
	inline char operator[](int i) { return S[si][a + i]; }
	string str() { return S[si].substr(a, b - a + 1); }
} ce;

int suf[N], p[N];
map<char, edge> tr[N];
int si = -1;

void sufftree(string s) {
	s += '$'; S[++si] = s;
	ns = cn = cd = 0; int i = 0, j, n = s.size();
	for(j = 0; j < n; j++)
		for(; i <= j; i++) {
			if(ns && !cd) suf[ns] = cn, ns = 0;
			if(cd? ce[cd] == s[j] : tr[cn].count(s[j])) {
				if(cd++ == 0) ce = tr[cn][s[j]];
				if(cd == ce.len()) cd = 0, cn = ce.v;
				break;
			} else if(cd) {
				if(ns) suf[ns] = en;
				tr[en][ce[cd]] = {ce.a + cd, ce.b, ce.v, ce.si};
				tr[en][s[j]] = {j, n - 1, en + 1, si};
				tr[cn][ce[0]] = {ce.a, ce.a + cd - 1, en, ce.si};
				p[en] = cn; p[en + 1] = p[ce.v] = en;
				ns = en;
				en += 2;
				int g = cn? j - cd : i + 1;
				cn = suf[cn];
				while(g < j && g + tr[cn][s[g]].len() <= j) {
					ce = tr[cn][s[g]];
					cn = ce.v;
					g += ce.len();
				}
				cd = j - g;
				if(cd) ce = tr[cn][s[g]];
			} else {
				p[en] = cn;
				tr[cn][s[j]] = {j, n - 1, en++, si};
				cn = suf[cn];
			}
		}
}

void clear_all() {
	for(int i = 0; i < en; i++)
		tr[i].clear();
	en = 1; si = -1;
}


int no[26*N], bn;
pii seg[26*N]; int m, sn = 1;
int L[26*N], R[26*N];
int he[N];
multiset<int> oc[N];

int node() { if(bn) return no[--bn]; else return sn++; }

int vis(int &i, int l) { if(!i) i = node(), seg[i] = pii(0, -l); return i; }

void add(int &i, int l, int r, int x) {
	vis(i, l);
	if(l == r) { seg[i].fst++; return; }
	int m = (l + r) / 2;
	if(x <= m) add(L[i], l, m, x);
	else add(R[i], m + 1, r, x);
	seg[i] = max(seg[vis(L[i], l)], seg[vis(R[i], m + 1)]);
}

void clear(int &i) {
	if(!i) return;
	if(bn < 26*N) no[bn++] = i;
	clear(L[i]); clear(R[i]);
	L[i] = R[i] = 0;
}

// chame pra todas strings pra marcar os finais
void proc(string &s, int si) {
	cn = cd = 0;
	for(char c : s) {
		if(cd++ == 0) ce = tr[cn][c];
		if(cd == ce.len()) cd = 0, cn = ce.v;
	}
	// marque o fim de si no vert cn
	if(si) add(he[cn], 0, m, si), oc[cn].insert(si);
	else no[0] = cn;
	for(int i = 1; i < s.size(); i++) {
		cn = p[cn];
		int g = cn? s.size() - ce.len() : i;
		cn = suf[cn];
		while(g != s.size()) {
			ce = tr[cn][s[g]];
			g += ce.len();
			cn = ce.v;
		}
		// marque o fim de si no vert cn
		if(si) add(he[cn], 0, m, si), oc[cn].insert(si);
		else no[i] = cn;
	}
}

char s[MX];
// l e r 1-indexado
struct query {
	int sz, l, r, i;
	bool operator < (query o) const { return sz < o.sz; }
};
priority_queue<query> qs[N];
pii ans[MX];

void joinq(priority_queue<query> &a, priority_queue<query> &b) {
	if(a.size() < b.size()) a.swap(b);
	while(!b.empty())
		a.push(b.top()), b.pop();
}

void joins(int a, int b) {
	if(oc[a].size() < oc[b].size()) swap(he[a], he[b]), oc[a].swap(oc[b]);
	clear(he[b]);
	for(int x : oc[b])
		add(he[a], 0, m, x);
	oc[a].insert(oc[b].begin(), oc[b].end());
	oc[b].clear();
}

pii get(int &i, int l, int r, int ql, int qr) {
	if(l > qr || r < ql) return pii(-1, -1);
	vis(i, l);
	if(l >= ql && r <= qr) return seg[i];
	int m = (l + r) / 2;
	return max(get(L[i], l, m, ql, qr), get(R[i], m + 1, r, ql, qr));
}

void deb(int u, int beg, int end, string s) {
	printf("[%2d..%2d] %s:", beg, end, s.c_str());
	for(int x : oc[u]) printf(" %d", x);
	putchar('\n');
}

void dfs(int u, int beg, int end/*, string s*/) {
	for(auto e : tr[u]) {
		int v = e.snd.v;
		dfs(v, end + 1, end + e.snd.len()/*, s + e.snd.str()*/);
		joinq(qs[u], qs[v]);
		joins(u, v);
	}
	//deb(u, beg, end, s);
	while(!qs[u].empty() && qs[u].top().sz > beg) {
		query q = qs[u].top(); qs[u].pop();
		ans[q.i] = get(he[u], 0, m, q.l, q.r);
		//printf("[%d..%d] ans[%d] = (%d, %d)\n", beg, end, q.i, ans[q.i].fst, ans[q.i].snd);
	}
}

int main() {
	seg[0] = pii(-1, -1);
	int i, j, n, l, r, pl, pr, q;
	scanf("%s", s);
	sufftree(s);
	scanf("%d", &m);
	for(i = 0; i < m; i++) {
		scanf("%s", s);
		sufftree(s);
	}
	for(i = 0; i <= m; i++)
		proc(S[i], i);
	scanf("%d", &q);
	for(i = 0; i < q; i++) {
		scanf("%d %d %d %d", &l, &r, &pl, &pr);
		qs[no[pl - 1]].push({pr - pl + 1, l, r, i});
	}
	dfs(0, -1, -1/*, ""*/);
	for(i = 0; i < q; i++)
		printf("%d %d\n", -ans[i].snd, ans[i].fst);
}