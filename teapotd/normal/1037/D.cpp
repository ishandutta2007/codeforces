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

struct Vert {
	Vi E;
	bool visited{0}, neigh{0};
};

vector<Vert> G;

void ans(bool x) {
	cout << (x ? "Yes" : "No") << endl;
	exit(0);
}

void run() {
	int n; cin >> n;
	G.resize(n);

	rep(i, 1, n) {
		int a, b; cin >> a >> b;
		G[a-1].E.pb(b-1);
		G[b-1].E.pb(a-1);
	}

	Vi seq(n);
	each(x, seq) {
		cin >> x;
		x--;
	}

	if (seq[0] != 0) ans(0);

	queue<int> que;
	que.push(0);
	G[0].visited = 1;

	int head = 1;

	while (!que.empty()) {
		int v = que.front();
		que.pop();

		Vi neigh;
		each(e, G[v].E) if (!G[e].visited) {
			neigh.pb(e);
			G[e].neigh = 1;
		}

		rep(i, 0, sz(neigh)) {
			int cur = seq[head++];
			if (G[cur].visited || !G[cur].neigh) ans(0);
			G[cur].neigh = 0;
			G[cur].visited = 1;
			que.push(cur);
		}
	}

	ans(1);
}