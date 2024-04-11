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
#define _deb(...)(DD("#, "#__VA_ARGS__,__LINE__,__VA_ARGS__),cerr<<endl)
using ll=long long;pri(a.print)"{",a.print(),o<<"}";}using namespace std;void DD(...){}using Pii=pair<int
,int>;tem void DD(t s,u a,w...k){while(*s&&*s!=',')cerr<<*s++;cerr<<": "<<a<<*s++;DD(s,k...);}pri(all)"["
,[&](){for(auto i : a)o<<i<<", ";}(),o<<"]";}using  Vi=vector<int>;pri(get<1>) "("<<a.x<<", "<<a.y<<")";}
//-----------------------------------------------------------------------------------------------------//

struct Vert {
	Vi edges, depths;
	int dom{0}, result{0};
	bool visited{false};
};

int n;
vector<Vert> V;

void merge(Vert& dst, Vert& src) {
	if (sz(dst.depths) < sz(src.depths)) {
		dst.depths.swap(src.depths);
		dst.dom = src.dom;
	}

	rep(i, 0, sz(src.depths)) {
		int to = sz(dst.depths) - sz(src.depths) + i;
		dst.depths[to] += src.depths[i];
	}

	rep(i, 0, sz(src.depths)) {
		int to = sz(dst.depths) - sz(src.depths) + i;
		if (dst.depths[dst.dom] <= dst.depths[to]) {
			dst.dom = to;
		}
	}
}

void dfs(int i) {
	auto& vert = V[i];
	if (vert.visited) return;
	vert.visited = true;

	each(e, vert.edges) if (!V[e].visited) {
		dfs(e);
		merge(vert, V[e]);
	}

	vert.depths.pb(1);
	if (vert.depths[vert.dom] == 1) vert.dom = sz(vert.depths) - 1;
	vert.result = sz(vert.depths) - vert.dom - 1;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> n;
	V.resize(n);

	rep(i, 1, n) {
		int a, b; cin >> a >> b;
		a--; b--;
		V[a].edges.pb(b);
		V[b].edges.pb(a);
	}

	dfs(0);
	each(vert, V) cout << vert.result << endl;
	return 0;
}