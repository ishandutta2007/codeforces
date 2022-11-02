#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
int cmp(double a, double b, double eps=1e-9) { return (a>b+eps) - (a+eps<b); }

struct Vert {
	Vi out, in;
	int flag{-1};
};

vector<Vert> G;
vector<Vi> sources;
Vi sinks;
int cur{0};

void findSinks(Vi& out, int v) {
	if (G[v].flag == cur) return;
	G[v].flag = cur;

	if (sz(G[v].out) == 0) {
		out.pb(v);
	}

	each(e, G[v].out) {
		findSinks(out, e);
	}
}

void run() {
	int n, m; cin >> n >> m;
	G.resize(n);

	rep(i, 0, m) {
		int a, b; cin >> a >> b;
		G[a-1].out.pb(b-1);
		G[b-1].in.pb(a-1);
	}

	rep(i, 0, sz(G)) {
		if (G[i].in.empty()) {
			sources.emplace_back();
			cur++;
			findSinks(sources.back(), i);
			sort(all(sources.back()));
		}
		if (G[i].out.empty()) {
			sinks.pb(i);
		}
	}

	rep(i, 1, (1<<sz(sources))-1) {
		Vi cut, tmp;

		rep(b, 0, sz(sources)) {
			if ((i>>b) & 1) {
				tmp.clear();
				set_union(all(sources[b]), all(cut), back_inserter(tmp));
				tmp.swap(cut);
			}
		}

		if (__builtin_popcount(i) >= sz(cut)) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}