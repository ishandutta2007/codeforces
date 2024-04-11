#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890123456789LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

struct line {
	cat A, C, Db, De;

	bool operator<(const line & L) const {
		if(A != L.A) return A < L.A;
		return C < L.C;
	}

	line operator+(const line & L) const {
		return {A+L.A, C+L.C, 0, 0};
	}

	cat val(cat x) {
		return x * A + C;
	}
};

typedef struct {
	int v;
	line l;
} edge;

vector<int> comp, S, group;
vector<line> dist;

void DFS(int R, int par, vector< vector<edge> > & G, vector<bool> & bl) {
	comp.push_back(R);
	S[R] = 1;
	int g = 1;
	for(int i = 0; i < (int)G[R].size(); i++) if(!bl[G[R][i].v] && par != G[R][i].v) {
		if(R == par) group[G[R][i].v] = g++;
		else group[G[R][i].v] = group[R];
		dist[G[R][i].v] = dist[R] + G[R][i].l;
		DFS(G[R][i].v, R, G, bl);
		S[R] += S[G[R][i].v];
	}
}

cat MX = 1200000;

vector<line> add_hulls(vector<line> & H1, vector<line> & H2) {
	assert(!H1.empty() && !H2.empty());
	vector<line> ret;
	int a1 = 0, a2 = 0, n1 = H1.size(), n2 = H2.size();
	cat x = 0;
	while(a1+1 < n1 || a2+1 < n2) {
		// H1[a1].Db >= x, H2[a2].Db >= x
		cat x_nxt = min(H1[a1].De, H2[a2].De);
		if(a1+1 == n1) x_nxt = H2[a2].De;
		if(a2+1 == n2) x_nxt = H1[a1].De;
		ret.push_back(H1[a1]+H2[a2]);
		ret.back().Db = x;
		ret.back().De = x_nxt;
		x = x_nxt+1;
		if(a1+1 < n1 && H1[a1].De == x_nxt) a1++;
		if(a2+1 < n2 && H2[a2].De == x_nxt) a2++;
	}
	ret.push_back(H1[a1]+H2[a2]);
	ret.back().Db = x;
	return ret;
}

vector<line> merge_hulls(vector<line> & H1, vector<line> & H2) {
	int n1 = H1.size(), n2 = H2.size();
	vector<line> Hm(n1+n2);
	merge(begin(H1), end(H1), begin(H2), end(H2), begin(Hm));
	int nm = n1+n2;
	vector<line> ret;
	for(int i = 0; i < nm; i++) {
		while(!ret.empty() && ret.back().A == Hm[i].A) ret.pop_back();
		while((int)ret.size() > 1) {
			line & l1 = Hm[i];
			line & l2 = ret.back();
			line & l3 = ret[ret.size()-2];
			// l1.C+l1.A*x <= l2.C+l2.A*x => l3.C+l3.A*x >= l2.C+l2.A*x
			cat x = (l2.C-l1.C) / (l1.A-l2.A);
			if(l1.val(x) > l2.val(x)) x--;
			if(l3.val(x) >= l2.val(x)) ret.pop_back();
			else break;
		}
		ret.push_back(Hm[i]);
	}
	assert(!ret.empty());
	for(int i = 1; i < (int)ret.size(); i++) {
		ret[i-1].De = (ret[i-1].C-ret[i].C) / (ret[i].A-ret[i-1].A);
		if(ret[i].A * ret[i-1].De + ret[i].C > ret[i-1].A * ret[i-1].De + ret[i-1].C) ret[i-1].De--;
		ret[i].Db = ret[i-1].De+1;
	}
	while((int)ret.size() > 1 && ret.back().Db > MX) ret.pop_back();
	reverse(begin(ret), end(ret));
	while((int)ret.size() > 1 && ret.back().De < 0) ret.pop_back();
	reverse(begin(ret), end(ret));
	ret[0].Db = 0;
	return ret;
}

vector<line> build_hull(vector<line> & H) {
	sort(begin(H), end(H));
	vector<line> He;
	return merge_hulls(H, He);
}

vector<line> build_hull(vector< vector<line> > & H) {
	vector<line> Hm;
	for(int i = 0; i < (int)H.size(); i++)
		ALL_THE(H[i], it) Hm.push_back(*it);
	return build_hull(Hm);
}

pair< vector<line>, vector<line> > solve_inner(vector< vector<line> > & hull_g, int l, int r) {
	if(l+1 == r) return {hull_g[l], hull_g[l]};
	int c = (l + r) / 2;
	pair< vector<line>, vector<line> > Vl = solve_inner(hull_g, l, c);
	pair< vector<line>, vector<line> > Vr = solve_inner(hull_g, c, r);
	vector<line> added = merge_hulls(Vl.ff, Vr.ff);
	vector<line> merged = merge_hulls(Vl.ss, Vr.ss);
	vector<line> added2 = add_hulls(Vl.ss, Vr.ss);
	return {merge_hulls(added, added2), merged};
}

void solve(int R, vector< vector<edge> > & G, vector<bool> & bl, vector< vector<line> > & hulls) {
	comp.clear();
	DFS(R, R, G, bl);
	if(comp.size() == 1) return;
	int C = -1;
	ALL_THE(comp, it) {
		if(2*S[*it] < S[R]) continue;
		bool is_cent = true;
		ALL_THE(G[*it], jt) if(!bl[jt->v] && S[jt->v] < S[*it] && 2*S[jt->v] > S[R]) {
			is_cent = false;
			break;
		}
		if(is_cent) {
			C = *it;
			break;
		}
	}
	comp.clear();
	dist[C] = {0, 0, 0, 0};
	group[C] = 0;
	DFS(C, C, G, bl);
	int g = 1; // number of groups
	ALL_THE(G[C], it) if(!bl[it->v]) g++;

	vector< vector<line> > lines_g(g);
	ALL_THE(comp, it) {
		bool leaf = true;
		ALL_THE(G[*it], jt) if(!bl[jt->v] && S[jt->v] < S[*it]) {
			leaf = false;
			break;
		}
		if(!leaf) continue;
		lines_g[group[*it]].push_back(dist[*it]);
	}
	lines_g[0].push_back({0, 0, 0, 0});

	vector< vector<line> > hull_g(g);
	for(int i = 0; i < g; i++) hull_g[i] = build_hull(lines_g[i]);

	pair< vector<line>, vector<line> > V = solve_inner(hull_g, 0, g);
	hulls.push_back(V.ff);

	bl[C] = true;
	ALL_THE(G[C], it) if(!bl[it->v]) solve(it->v, G, bl, hulls);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector< vector<edge> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v, a, c;
		cin >> u >> v >> a >> c;
		G[--u].push_back({--v, {a, c, 0, 0}});
		G[v].push_back({u, {a, c, 0, 0}});
	}
	vector<bool> bl(N, false);
	vector< vector<line> > hulls = {{{0, 0, 0, M+1}}};
	S.resize(N);
	group.resize(N);
	dist.resize(N);
	solve(0, G, bl, hulls);
	int a = 0;
	vector<line> hull = build_hull(hulls);
	for(int i = 0; i < M; i++) {
		while(a+1 < (int)hull.size() && hull[a].val(i) <= hull[a+1].val(i)) a++;
		cout << hull[a].val(i) << ((i == M-1) ? "\n" : " ");
	}
	return 0;
}

// look at my code
// my code is amazing