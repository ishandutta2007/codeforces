/*
 * Author       : YangDavid
 * Created Time : 2020.10.05 21:23:10
 */

#include<bits/stdc++.h>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
template<typename... Args> auto ndim(size_t sz0, Args&&... args) {
    if constexpr(sizeof...(args) == 1) return vector(sz0, args...);
    else return vector(sz0, ndim(args...));
}


const int INF = 0x3f3f3f3f;
#define Type int
struct Edge {
    int from, to;
    Type cap, flow;
    Edge(int u = 0, int v = 0, Type c = 0):
        from(u), to(v), cap(c), flow(0) { }
};
 
struct Dinic {
    int N;
    vector<Edge> edges;
    vector< vector<int> > adj;
    vector<int> d, cur;
 
    Dinic(int Num): N(Num + 20), edges(0), adj(Num + 20), d(Num + 20), cur(Num + 20) { }
 
    void addEdge(int u, int v, Type cap) {
        if(u == v) return;
        edges.emplace_back(u, v, cap);
        adj[u].emplace_back(edges.size() - 1);
        edges.emplace_back(v, u, 0);
        adj[v].emplace_back(edges.size() - 1);
    }
 
    bool bfs(int S, int T) {
        queue<int> q({S});
        fill(d.begin(), d.end(), N + 1);
        d[S] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if(u == T) break;
            for(int k : adj[u]) {
                Edge &e = edges[k];
                if(e.flow < e.cap && d[e.to] > d[e.from] + 1) {
                    d[e.to] = d[e.from] + 1;
                    q.emplace(e.to);
                }
            }
        }
        return d[T] != N + 1;
    }
 
    Type dfs(int u, int T, Type flow = -1) {
        if(u == T || flow == 0) return flow;
        for(int &i = cur[u]; i < int(adj[u].size()); ++i) {
            Edge &e = edges[adj[u][i]];
            Edge &re = edges[adj[u][i] ^ 1];
            if(d[e.to] == d[e.from] + 1) {
                Type rem = e.cap - e.flow;
                if(flow != -1 && rem > flow) rem = flow;
                Type pushed = dfs(e.to, T, rem);
                if(pushed > 0) {
                    e.flow += pushed;
                    re.flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
 
    Type maxFlow(int S, int T) {
        Type total = 0;
        while(bfs(S, T)) {
            fill(cur.begin(), cur.end(), 0);
            while(Type flow = dfs(S, T))
                total += flow;
        }
        return total;
    }
};
#undef Type
 
const int MAXN = 202020;
int n, m;
struct E { int u, v, w; bool operator < (const E& rhs) const { return w<rhs.w; } } e[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		e[i].v += n;
	}
	sort(e, e + m);
	int l = 0, r = m-1;
	auto check = [&](int mid) {
		Dinic dic(2*n+2);
		for(int i = 1; i <= n; ++i) {
			dic.addEdge(2*n+1, i, 1);
			dic.addEdge(i+n, 2*n+2, 1);
		}
		for(int i = 0; i <= min(mid, m-1); ++i)
			dic.addEdge(e[i].u, e[i].v, 1);
		return dic.maxFlow(2*n+1, 2*n+2) == n;
	};
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid))
			r = mid;
		else l = mid + 1;
	}
	printf("%d\n", !check(l) ? -1 : e[l].w);
    return 0;
}