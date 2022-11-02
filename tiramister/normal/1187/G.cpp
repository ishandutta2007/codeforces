#include <iostream>
#include <vector>
#include <limits>

template <class Cap, class Cost, bool isDirect>
class MinCostFlow {
    struct Edge {
        int src, dst;
        Cap cap;
        Cost cost;
        int rev;
        Edge(int src, int dst, Cap cap, Cost cost, int rev)
            : src(src), dst(dst), cap(cap), cost(cost), rev(rev){};
    };

    class Graph {
    public:
        int size;
        std::vector<std::vector<Edge>> path;

        explicit Graph(int N = 0) : size(N), path(size) {}
        void span(int src, int dst, Cap cap, Cost cost, int rev) {
            path[src].push_back(Edge(src, dst, cap, cost, rev));
        }
        std::vector<Edge>& operator[](int v) { return path[v]; }
    };

public:
    const Cost INF = std::numeric_limits<Cost>::max();
    Graph graph;
    std::vector<Cost> dist;
    std::vector<Edge*> rev;

    explicit MinCostFlow(int N) : graph(N), dist(N), rev(N) {}

    void span(int src, int dst, Cap cap, Cost cost) {
        graph.span(src, dst, cap, cost, graph[dst].size());
        graph.span(dst, src, (isDirect ? 0 : cap), -cost, graph[src].size() - 1);
    }

    void BellmanFord(int s) {
        fill(dist.begin(), dist.end(), INF);
        dist[s] = 0;

        bool update = true;
        while (update) {
            update = false;
            for (int v = 0; v < graph.size; ++v) {
                if (dist[v] == INF) continue;
                for (auto& e : graph[v]) {
                    if (e.cap > 0 && dist[e.dst] > dist[e.src] + e.cost) {
                        dist[e.dst] = dist[e.src] + e.cost;
                        rev[e.dst] = &e;
                        update = true;
                    }
                }
            }
        }
    }

    Cost exec(int s, int g, Cap flow) {
        Cost ret = 0;

        while (flow > 0) {
            BellmanFord(s);
            if (dist[g] == INF) break;

            Cap f = flow;
            int v = g;
            while (v != s) {
                f = std::min(f, rev[v]->cap);
                v = rev[v]->src;
            }
            flow -= f;
            ret += f * dist[g];

            v = g;
            while (v != s) {
                // rev[v]->dst = v
                rev[v]->cap -= f;
                graph[v][rev[v]->rev].cap += f;
                v = rev[v]->src;
            }
        }
        return (flow > 0 ? -1 : ret);
    }
};


using namespace std;

const int INF = numeric_limits<int>::max() / 3;
constexpr int MAXD = 100, S = 5000, G = 5001;

int ecd(int v, int d) {
    return v + d * 50;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K, C, D;
    cin >> N >> M >> K >> C >> D;

    MinCostFlow<int, int, true> mcf(5002);

    // source
    for (int i = 0; i < K; ++i) {
        int v;
        cin >> v;
        --v;
        mcf.span(S, ecd(v, 0), 1, 0);
    }

    // sink
    for (int d = 0; d < MAXD; ++d) {
        mcf.span(ecd(0, d), G, INF, C * d);
    }

    // stay
    for (int v = 0; v < N; ++v) {
        for (int d = 0; d + 1 < MAXD; ++d) {
            mcf.span(ecd(v, d), ecd(v, d + 1), INF, 0);
        }
    }

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        for (int d = 0; d + 1 < MAXD; ++d) {
            for (int k = 0; k < K; ++k) {
                // path for k-th person
                // 1 + 3 + ... + (2k-1) = k^2
                mcf.span(ecd(u, d), ecd(v, d + 1), 1, D * (k * 2 + 1));
                mcf.span(ecd(v, d), ecd(u, d + 1), 1, D * (k * 2 + 1));
            }
        }
    }

    cout << mcf.exec(S, G, K) << endl;
    return 0;
}