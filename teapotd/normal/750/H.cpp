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
	int ver{-1};
	int defPar{-1}, par;
	bool defBlocked{1}, blocked;
};

int hei, wid, nQuestions;
vector<Vert> G;
set<Pii> permEdges, tempEdges;
int currentVer = 1;

void update(int i) {
	if (G[i].ver != currentVer) {
		G[i].ver = currentVer;
		G[i].par = G[i].defPar;
		G[i].blocked = G[i].defBlocked;
	}
}

int find(int i) {
	update(i);
	if (G[i].par == -1) return i;
	return G[i].par = find(G[i].par);
}

int join(int i, int j) {
	i = find(i);
	j = find(j);
	if (i == j) return i;
	if (rand() % 2) swap(i, j);
	return G[i].par = j;
}

int ind(int x, int y) { return x*wid+y; }
Vert& vert(int i) { update(i); return G[i]; }
Vert& vert(int x, int y) { return vert(ind(x, y)); }

void eachNeigh(int i, int j, function<void(int,int)> func) {
	rep(dx, -1, 2) rep(dy, -1, 2) if (dx != 0 || dy != 0) {
		int x = i+dx, y = j+dy;
		if (x >= 0 && y >= 0 && x < hei && y < wid) {
			func(x, y);
		}
	}
}

void addEdges(int i, int j) {
	assert(vert(i, j).blocked);

	eachNeigh(i, j, [&](int x, int y) {
		if (vert(x, y).blocked) return;
		eachNeigh(x, y, [&](int a, int b) {
			if (vert(a, b).blocked) {
				int p1 = find(ind(i, j)), p2 = find(ind(a, b));
				tempEdges.insert({ p1, p2 });
				tempEdges.insert({ p2, p1 });
			}
		});
	});
}

void query() {
	int k; cin >> k;
	vector<Pii> toBlock(k);
	each(p, toBlock) cin >> p.x >> p.y;

	Vi toCheck;
	currentVer++;
	tempEdges.clear();

	each(p, toBlock) {
		vert(p.x, p.y).blocked = 1;
		toCheck.pb(find(ind(p.x, p.y)));

		eachNeigh(p.x, p.y, [&](int i, int j) {
			if (vert(i, j).blocked) {
				toCheck.pb(find(ind(i, j)));
				join(ind(i, j), ind(p.x, p.y));
			}
		});

		addEdges(p.x, p.y);
		toCheck.pb(find(ind(p.x, p.y)));

		eachNeigh(p.x, p.y, [&](int i, int j) {
			if (vert(i, j).blocked) {
				toCheck.pb(find(ind(i, j)));
			}
		});
	}

	int top = find(ind(0, 3)), bottom = find(ind(3, 0));
	toCheck.pb(top);
	toCheck.pb(bottom);

	each(i, toCheck) if (find(i) == top) {
		each(j, toCheck) if (find(j) == bottom) {
			if (permEdges.count({i, j}) || tempEdges.count({i, j})) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
}

void run() {
	cin >> hei >> wid >> nQuestions;
	hei += 2;
	wid += 2;

	G.resize(hei*wid);
	rep(i, 0, 3) {
		vert(i, 0).defBlocked = vert(0, i).defBlocked = 0;
		vert(hei-i-1, wid-1).defBlocked = vert(hei-1, wid-i-1).defBlocked = 0;
	}

	rep(i, 1, hei-1) {
		string tmp; cin >> tmp;
		rep(j, 1, wid-1) vert(i, j).defBlocked = (tmp[j-1] == '#');
	}

	rep(x, 0, hei) rep(y, 0, wid) {
		auto& cur = vert(x, y);
		if (!cur.defBlocked) continue;

		eachNeigh(x, y, [&](int i, int j) {
			if (vert(i, j).defBlocked) {
				join(ind(x, y), ind(i, j));
			}
		});
	}

	each(v, G) v.defPar = v.par;
	currentVer++;

	rep(i, 0, hei) rep(j, 0, wid) {
		auto& cur = vert(i, j);
		if (cur.defBlocked) addEdges(i, j);
	}

	swap(tempEdges, permEdges);
	while (nQuestions--) query();
}