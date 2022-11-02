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

int n;
vector<string> graph;
Vi fuRoot, fuRank, scc;
Vi graph2;

int getRoot(int v) {
	if (fuRoot[v] < 0) return v;
	return fuRoot[v] = getRoot(fuRoot[v]);
}

void fuUnion(int a, int b) {
	a = getRoot(a);
	b = getRoot(b);
	if (a == b) return;

	if (fuRank[a] < fuRank[b]) {
		fuRoot[a] = b;
	} else if (fuRank[a] > fuRank[b]) {
		fuRoot[b] = a;
	} else {
		fuRoot[a] = b;
		fuRank[b]++;
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> n;
	graph.resize(n);
	each(x, graph) cin >> x;

	fuRoot.resize(n, -1);
	fuRank.resize(n, 0);
	scc.resize(n, -2);

	rep(i, 0, n) rep(j, 0, n) if (graph[i][j] == 'A') fuUnion(i, j);

	rep(i, 0, n) rep(j, 0, n) if (graph[i][j] == 'X' && getRoot(i) == getRoot(j)) {
		cout << "-1\n";
		return 0;
	}

	rep(i, 0, n) {
		int j = getRoot(i);
		if (scc[j] == -2) {
			scc[j] = -1;
		} else if (scc[j] == -1) {
			scc[j] = sz(graph2);
			graph2.emplace_back();
		}
	}
	rep(i, 0, n) scc[i] = scc[getRoot(i)];

	rep(i, 0, n) if (scc[i] >= 0) rep(j, 0, n) if (scc[j] >= 0 && graph[i][j] == 'X') {
		graph2[scc[i]] |= (1 << scc[j]);
	}

	int best = sz(graph2);
	Vi perm(sz(graph2)), cliques;
	iota(all(perm), 0);

	while (double(clock()) < CLOCKS_PER_SEC*4.9) {
		random_shuffle(all(perm));
		cliques.clear();

		each(i, perm) {
			each(c, cliques) {
				if ((c & graph2[i]) == 0) {
					c |= 1 << i;
					goto next;
				} 
			}
			cliques.pb(1 << i);
			next:;
		}

		best = min(best, sz(cliques));
	}

	cout << (n + best - 1) << endl;
	return 0;
}