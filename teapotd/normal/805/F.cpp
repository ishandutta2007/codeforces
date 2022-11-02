#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>

#define mp make_pair
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define repd(i,b,e)for(int i=(b);i>=(e);i--)
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define sz(x)int((x).size())
#define TM template<class T,class U=int,class...V>
#define DF(t,...)TM auto operator<<(ostream&o,__VA_ARGS__ x)->decltype(t,cout)
#define DD(...)void print(){cerr<<'{';dbgx(#__VA_ARGS__,__VA_ARGS__);cerr<<'}';}
#ifdef LOC
#define dbg(...)(cerr<<"<"<<__LINE__,dbgx("> "#__VA_ARGS__,__VA_ARGS__),cerr<<"\n")
#else
#define dbg(...)
#endif
using namespace std;using namespace rel_ops;using ll=int64_t;using Vi=vector<int>;using Pii=pair<int,int>;
void dbgx(...){}TM void dbgx(T s,U a,V...b){while(*s&&*s!=',')cerr<<*s++;cerr<<": "<<a<<*s++;dbgx(s,b...);}
DF(&T::print,T){x.print();return o;}DF(0,pair<T,U>){return o<<"("<<x.first<<", "<<x.second<<")";}
DF(T().begin(),T){o<<"[";each(e,x)o<<e<<", ";return o<<"]";}

// ----------------------------------------------------------------------------------------------------- //

struct Vert {
	Vi edges;
	int state{0}, comp{-1};
	ll dist{0};

	DD(edges, dist, comp);
};

int V, E, Q;
vector<Vert> verts;
vector<vector<ll>> comps, prefs;
Vert* far;
map<Pii, double> results;

void dfs(Vert& v, ll d, int pass) {
	if (v.state == pass) return;
	v.state = pass;
	v.dist = d;

	if (!far || far->dist < d) far = &v;
	each(e, v.edges) dfs(verts[e], d+1, pass);
}

void dfs2(Vert& v, ll d) {
	if (v.comp >= 0) return;
	v.comp = sz(comps)-1;

	v.dist = max(v.dist, d);
	comps.rbegin()->push_back(v.dist);

	each(e, v.edges) dfs2(verts[e], d+1);
}

void query() {
	int a, b; cin >> a >> b;
	a = verts[a-1].comp;
	b = verts[b-1].comp;

	if (a == b) {
		cout << "-1\n";
		return;
	}

	if (a > b) swap(a, b);
	if (sz(comps[a]) > sz(comps[b])) swap(a, b);

	if (results.count(mp(a, b))) {
		cout << results[mp(a, b)] << endl;
		return;
	}

	auto &ca = comps[a], &cb = comps[b];
	ll diam = max(*ca.rbegin(), *cb.rbegin());
	ll upper = 0;

	rep(i, 0, sz(ca)) {
		ll j = ll(lower_bound(all(cb), diam - ca[i] - 1) - cb.begin());
		upper += diam*j;
		upper += *prefs[b].rbegin() - prefs[b][j] + ll(sz(cb)-j)*(ca[i]+1);
	}

	double ret = double(upper) / double(sz(ca)) / double(sz(cb));
	results[mp(a, b)] = ret;
	cout << ret << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> V >> E >> Q;
	verts.resize(V);

	rep(i, 0, E) {
		int a, b; cin >> a >> b; a--; b--;
		verts[a].edges.push_back(b);
		verts[b].edges.push_back(a);
	}

	each(v, verts) {
		if (v.comp >= 0) continue;
		comps.emplace_back();
		prefs.emplace_back();

		far = nullptr;
		dfs(v, 0, 1);

		auto one = far;
		far = nullptr;
		dfs(*one, 0, 2);
		dfs2(*far, 0);

		sort(all(*comps.rbegin()));

		ll sum = 0;
		prefs.rbegin()->push_back(0);
		each(x, *comps.rbegin()) {
			sum += x;
			prefs.rbegin()->push_back(sum);
		}
	}

	rep(i, 0, V) dbg(i, verts[i]);
	dbg(comps);
	dbg(prefs);

	while (Q--) query();
	return 0;
}