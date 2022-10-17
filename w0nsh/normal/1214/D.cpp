#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
    struct Edge {
        int from, to, cap, flow;
        Edge() {}
        Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
    };
 
using namespace std;
const int N = 2000000;
const int INF = 1e9 + 7;
vector<Edge> edges;
vector<int> G[N];
bitset<N> vis;
int d[N], cur[N];

struct Dinic {
 
 
    void init(int n) {
        for(int i = 0; i <= n; i++) G[i].clear();
        edges.clear();
    }
 
    void addEdge(int from, int to, int cap) {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        int t_m = edges.size();
        G[from].push_back(t_m - 2);
        G[to].push_back(t_m - 1);
    }
 
    bool BFS(int s, int t) {
        vis.reset();
        queue<int> Q;
        Q.push(s);
        d[s] = 0; vis[s] = 1;
        while(Q.size()) {
            int x = Q.front(); Q.pop();
            for(int i = 0; i < G[x].size(); i++) {
                Edge& e = edges[G[x][i]];
                if(!vis[e.to] and e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }
 
    int DFS(int x, int a, int s, int t) {
        if(x == t or a == 0) return a;
        int flow = 0, _f;
        for(int& i = cur[x]; i < G[x].size(); i++) {
            Edge& e = edges[G[x][i]];
            if(d[x] + 1 == d[e.to] and (_f = DFS(e.to, min(a, e.cap - e.flow), s, t)) > 0) {
                e.flow += _f;
                edges[G[x][i] ^ 1].flow -= _f;
                flow += _f;
                a -= _f;
                if(a == 0) {
                    break;
                }
            }
        }
        return flow;
    }
 
    int maxFlow(int s, int t) {
        int flow = 0;
        while(BFS(s, t)) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF, s, t);
        }
        return flow;
    }
};

char tab[1000005];
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;

	FOR(i, n) FOR(j, m){
		int ind = i*m+j;
		std::cin >> tab[ind];
	}
	Dinic dinic = Dinic();
	FOR(i, n) FOR(j, m){
		if(tab[i*m+j] == '.') dinic.addEdge(2*(i*m+j), 2*(i*m+j)+1, (i*m+j == 0 || i*m+j == n*m-1 ? 2 : 1));
		if(j < m-1) dinic.addEdge(2*(i*m+j)+1, 2*(i*m+j+1), 1);
		if(i < n-1) dinic.addEdge(2*(i*m+j)+1, 2*((i+1)*m+j), 1);
	}
	std::cout << dinic.maxFlow(0, 2*(n*m-1)+1);
	return 0;
}