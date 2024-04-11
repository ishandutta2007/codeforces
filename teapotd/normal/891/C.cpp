#include <bits/stdc++.h>
#ifdef LOC
#define deb _deb
#else
#define deb(...)
#endif
#define x  first
#define y second
#define mp make_pair
#define pb push_back
#define sz(x)int((x).size())
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define tem template<class t,class u,class...w>
#define DBP(...)void print(...){DD(#__VA_ARGS__,__VA_ARGS__);}
#define pri(y)tem auto operator<<(t&o,u a)->decltype(y(a),o){return o<<
#define _deb(...)(DD("#, "#__VA_ARGS__,__LINE__,__VA_ARGS__),cerr<<'\n')
using ll=long long;pri(a.print)"{",a.print(),o<<"}";}using namespace std;void DD(...){}using Pii=pair<int
,int>;tem void DD(t s,u a,w...k){while(*s&&*s!=',')cerr<<*s++;cerr<<": "<<a<<*s++;DD(s,k...);}pri(all)"["
,[&](){for(auto i : a)o<<i<<", ";}(),o<<"]";}using  Vi=vector<int>;pri(get<1>) "("<<a.x<<", "<<a.y<<")";}
//-----------------------------------------------------------------------------------------------------//

struct Vert {
	Vi edges;
	int parent{-1}, rank{0}, access{-1};

	DBP(edges, parent, rank, access);
};

struct Edge {
	int v1, v2, w, c1, c2;
	DBP(v1, v2, w, c1, c2);
};

int V, E;
vector<Vert> verts;
vector<Edge> edges;
int fuAccess = 0;

int fuParent(int v) {
	if (verts[v].access != fuAccess) {
		verts[v].access = fuAccess;
		verts[v].parent = -1;
	}

	if (verts[v].parent < 0) return v;
	return verts[v].parent = fuParent(verts[v].parent);
}

void fuUnion(int a, int b) {
	a = fuParent(a);
	b = fuParent(b);
	if (a == b) return;

	if (verts[a].rank < verts[b].rank) {
		verts[a].parent = b;
	} else if (verts[a].rank > verts[b].rank) {
		verts[b].parent = a;
	} else {
		verts[b].parent = a;
		verts[a].rank++;
	}
}

void preprocess() {
	vector<Edge*> sorted;
	each(e, edges) sorted.pb(&e);
	sort(all(sorted), [](Edge* l, Edge* r)->bool { return l->w < r->w; });

	for (int begin = 0; begin < E;) {
		int end = begin;

		for (; end < E; end++) {
			if (sorted[begin]->w != sorted[end]->w) break;
			auto& e = *sorted[end];
			e.c1 = fuParent(e.v1);
			e.c2 = fuParent(e.v2);
		}

		rep(i, begin, end) fuUnion(sorted[i]->v1, sorted[i]->v2);
		begin = end;
	}
}

void handle() {
	int k; cin >> k;
	bool ok = true;
	vector<Edge*> sorted(k);

	each(e, sorted) {
		int x; cin >> x;
		e = &edges[x-1];
	}
	sort(all(sorted), [](Edge* l, Edge* r) { return l->w < r->w; });

	for (int begin = 0; begin < k;) {
		int end = begin;
		fuAccess++;

		for (; end < k; end++) {
			auto& e = *sorted[end];
			if (sorted[begin]->w != e.w) break;
			if (fuParent(e.c1) == fuParent(e.c2)) {
				ok = false;
				break;
			}
			fuUnion(e.c1, e.c2);
		}

		if (!ok) break;
		begin = end;
	}

	cout << (ok ? "YES\n" : "NO\n");
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> V >> E;
	verts.resize(V);
	edges.resize(E);

	rep(i, 0, E) {
		Edge& e = edges[i];
		cin >> e.v1 >> e.v2 >> e.w;
		e.v1--; e.v2--;
		verts[e.v1].edges.pb(i);
		verts[e.v2].edges.pb(i);
	}

	preprocess();
	rep(i,0,V) deb(i, verts[i]);
	rep(i,0,E) deb(i, edges[i]);

	int Q; cin >> Q;
	while (Q--) handle();
	return 0;
}