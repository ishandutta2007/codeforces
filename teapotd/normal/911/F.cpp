#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define repd(i,b,e)for(int i=(b);i>=(e);i--)
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define sz(x)int((x).size())
#define tem template<class t,class...g>
#define D DD()
#define pri(k)tem auto p(t a,ll)->decltype(a.k,z()){D
#define DBP(...)void print(){D.x("{"#__VA_ARGS__,__VA_ARGS__);D,"}";}
#ifdef LOC
#define deb(...)((D,"<",__LINE__,"> ").x(#__VA_ARGS__,__VA_ARGS__),D,"\n")
#else
#define deb(...)
#endif
using namespace std;using namespace rel_ops;using ll=long long;using Vi=vector<int>;
using Pii=pair<int,int>;struct DD{using z=void;z x(...){}tem z p(t a,...){cerr<<a;}
tem DD&operator,(t a){p(a,0);return*this;}pri(first),"(",a.first,", ",a.second,")";}
tem z x(const char*s,t a,g...k){while(*s&&*s!=',')D,*s++;D,": ",a,*s++;x(s,k...);}
pri(print());a.print();}pri(begin()),"[";each(k,a)D,k,", ";D,"]";}};

// ------------------------------------------------------------------------------------------ //

struct Vert {
	Vi edges;
	int state{0}, dist{0}, paired{0}, deg{0};
};

int V;
vector<Vert> verts;
int far1 = 0, far2 = 0;

void dfs1(int i, int dist, int st) {
	auto& v = verts[i];
	if (v.state == st) return;
	v.state = st;

	v.dist = dist;
	v.paired = far1;

	each(e, v.edges) dfs1(e, dist+1, st);
}

void dfs2(int i, int dist) {
	auto& v = verts[i];
	if (v.state == 3) return;
	v.state = 3;

	if (v.dist < dist) {
		v.dist = dist;
		v.paired = far2;
	}

	each(e, v.edges) dfs2(e, dist+1);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> V;
	verts.resize(V);

	rep(i, 1, V) {
		int a, b; cin >> a >> b; a--; b--;
		verts[a].edges.pb(b);
		verts[b].edges.pb(a);
		verts[a].deg++;
		verts[b].deg++;
	}

	dfs1(0, 0, 1);
	rep(i, 0, V) if (verts[i].dist > verts[far1].dist) far1 = i;

	dfs1(far1, 0, 2);
	rep(i, 0, V) if (verts[i].dist > verts[far2].dist) far2 = i;

	dfs2(far2, 0);

	// ---

	ll ans = 0;
	vector<pair<Pii, int>> ret;

	queue<int> leaves;
	rep(i, 0, V) if (i != far1 && i != far2 && verts[i].deg == 1) {
		leaves.push(i);
	}

	while (!leaves.empty()) {
		int i = leaves.front();
		leaves.pop();
		ans += ll(verts[i].dist);
		ret.pb(mp(mp(i, verts[i].paired), i));

		each(e, verts[i].edges) if (--verts[e].deg == 1 && e != far1 && e != far2) {
			leaves.push(e);
		}
	}

	leaves.push(far1);
	int d = verts[far1].dist;

	while (!leaves.empty()) {
		int i = leaves.front();
		leaves.pop();
		ans += ll(d--);
		ret.pb(mp(mp(i, far2), i));

		each(e, verts[i].edges) if (--verts[e].deg == 1 && e != far2) {
			leaves.push(e);
		}
	}

	cout << ans << endl;
	each(x, ret) {
		cout << x.first.first+1 << " " << x.first.second+1 << " " << x.second+1 << endl;
	}
	return 0;
}