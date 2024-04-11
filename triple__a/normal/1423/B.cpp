#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#define all(v) (v).begin(), (v).end()
#define unq(v) (v).erase(unique(all(v)), (v).end())
#define ii int, int
#define li int, int
#define ll2 ll, ll
#define vec vector
#define pii pair <int, int>
#define pli pair <ll, int>
#define pil pair <int, ll>
#define pll2 pair <ll, ll>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define MULTI int T; cin >> T; while(T--)
#define sqr(x) ((x) * (x))
#define test cerr << '!' << endl;
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
int main0 ();
int main () {
	main0();
	return 0;
}

// Push relabel in O(V^2 E^0.5) with gap heuristic
// It's quite fast
template<typename flow_t = long long>
struct PushRelabel {
    struct Edge {
        int to, rev;
        flow_t f, c;
    };
    vector<vector<Edge> > g;
    vector<flow_t> ec;
    vector<Edge*> cur;
    vector<vector<int> > hs;
    vector<int> H;
    PushRelabel() {}
    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}
    void add_edge(int s, int t, flow_t cap, flow_t rcap=0) {
        if (s == t) return;
        Edge a = {t, (int)g[t].size(), 0, cap};
        Edge b = {s, (int)g[s].size(), 0, rcap};
        g[s].push_back(a);
        g[t].push_back(b);
    }
    void add_flow(Edge& e, flow_t f) {
        Edge &back = g[e.to][e.rev];
        if (!ec[e.to] && f)
            hs[H[e.to]].push_back(e.to);
        e.f += f; e.c -= f;
        ec[e.to] += f;
        back.f -= f; back.c += f;
        ec[back.to] -= f;
    }
    flow_t max_flow(int s, int t) {
        int v = g.size();
        H[s] = v;
        ec[t] = 1;
        vector<int> co(2*v);
        co[0] = v-1;
        for(int i=0;i<v;++i) cur[i] = g[i].data();
        for(auto &e:g[s]) add_flow(e, e.c);
        if(hs[0].size())
        for (int hi = 0;hi>=0;) {
            int u = hs[hi].back();
            hs[hi].pop_back();
            while (ec[u] > 0) // discharge u
                if (cur[u] == g[u].data() + g[u].size()) {
                    H[u] = 1e9;
                    for(auto &e:g[u])
                        if (e.c && H[u] > H[e.to]+1)
                            H[u] = H[e.to]+1, cur[u] = &e;
                    if (++co[H[u]], !--co[hi] && hi < v)
                        for(int i=0;i<v;++i)
                            if (hi < H[i] && H[i] < v){
                                --co[H[i]];
                                H[i] = v + 1;
                            }
                    hi = H[u];
                } else if (cur[u]->c && H[u] == H[cur[u]->to]+1)
                    add_flow(*cur[u], min(ec[u], cur[u]->c));
                else ++cur[u];
            while (hi>=0 && hs[hi].empty()) --hi;
        }
        return -ec[s];
    }
};

#define N 1000100
int n, m;
int u[N], v[N], w[N];
 
int main0 () {
	scanf("%d%d", &n, &m);
	int S = 2 * n + 1;
	int T = 2 * n + 2;
	for (int i = 1;i <= m;++i) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
	}
	
	int l = 1, r = 1e9;
	while (l <= r) {
		int mid = (l + r) / 2;
		PushRelabel<> X = PushRelabel<>(T + 1);
		for (int i = 1; i <= n; i++) {
			X.add_edge(S, i, 1);
			X.add_edge(i + n, T, 1);	
		}
		for (int i = 1; i <= m; i++) if (w[i] <= mid) {
			X.add_edge(u[i], v[i] + n, 1);	
		}
		
		int cur = X.max_flow(S, T);
		//cout << l << ' ' << r << ' ' << mid << ':' << cur << endl;
		if (cur == n) r = mid - 1;
		else l = mid + 1;
	}
	
	printf("%d\n", (l == 1000000001) ? -1 : l);
}