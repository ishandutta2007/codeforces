#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long haha = 0;

template <class T = int>
class MCMF {
public:
    struct Edge {
        Edge(int a, T b, T c) : to(a), cap(b), cost(c) {}
        int to;
        T cap, cost;
    };

    MCMF(int size) {
        n = size;
        edges.resize(n);
        pot.assign(n, 0);
        dist.resize(n);
        visit.assign(n, false);
    }

    std::pair<T, T> mcmf(int src, int sink, bool wtf = false) {
        std::pair<T, T> ans(0, 0);
        if(!SPFA(src, sink)) return ans;
        fixPot();
        // can use dijkstra to speed up depending on the graph
        while(SPFA(src, sink)) {
            auto flow = augment(src, sink);
            ans.first += flow.first;
            ans.second += flow.first * flow.second;
            fixPot();
            if(wtf) {
                haha = std::max((long long) -ans.second, haha);
            }
        }
        return ans;
    }

    void addEdge(int from, int to, T cap, T cost) {
        edges[from].push_back(list.size());
        list.push_back(Edge(to, cap, cost));
        edges[to].push_back(list.size());
        list.push_back(Edge(from, 0, -cost));
    }
private:
    int n;
    std::vector<std::vector<int>> edges;
    std::vector<Edge> list;
    std::vector<int> from;
    std::vector<T> dist, pot;
    std::vector<bool> visit;

    /*bool dij(int src, int sink) {
        T INF = std::numeric_limits<T>::max();
        dist.assign(n, INF);
        from.assign(n, -1);
        visit.assign(n, false);
        dist[src] = 0;
        for(int i = 0; i < n; i++) {
            int best = -1;
            for(int j = 0; j < n; j++) {
                if(visit[j]) continue;
                if(best == -1 || dist[best] > dist[j]) best = j;
            }
            if(dist[best] >= INF) break;
            visit[best] = true;
            for(auto e : edges[best]) {
                auto ed = list[e];
                if(ed.cap == 0) continue;
                T toDist = dist[best] + ed.cost + pot[best] - pot[ed.to];
                assert(toDist >= dist[best]);
                if(toDist < dist[ed.to]) {
                    dist[ed.to] = toDist;
                    from[ed.to] = e;
                }
            }
        }
        return dist[sink] < INF;
    }*/

    std::pair<T, T> augment(int src, int sink) {
        std::pair<T, T> flow = {list[from[sink]].cap, 0};
        for(int v = sink; v != src; v = list[from[v]^1].to) {
            flow.first = std::min(flow.first, list[from[v]].cap);
            flow.second += list[from[v]].cost;
        }
        for(int v = sink; v != src; v = list[from[v]^1].to) {
            list[from[v]].cap -= flow.first;
            list[from[v]^1].cap += flow.first;
        }
        return flow;
    }

    std::queue<int> q;
    bool SPFA(int src, int sink) {
        T INF = std::numeric_limits<T>::max();
        dist.assign(n, INF);
        from.assign(n, -1);
        q.push(src);
        dist[src] = 0;
        while(!q.empty()) {
            int on = q.front();
            q.pop();
            visit[on] = false;
            for(auto e : edges[on]) {
                auto ed = list[e];
                if(ed.cap == 0) continue;
                T toDist = dist[on] + ed.cost + pot[on] - pot[ed.to];
                if(toDist < dist[ed.to]) {
                    dist[ed.to] = toDist;
                    from[ed.to] = e;
                    if(!visit[ed.to]) {
                        visit[ed.to] = true;
                        q.push(ed.to);
                    }
                }
            }
        }
        return dist[sink] < INF;
    }

    void fixPot() {
        T INF = std::numeric_limits<T>::max();
        for(int i = 0; i < n; i++) {
            if(dist[i] < INF) pot[i] += dist[i];
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> atk, def, me;
    for(int i = 0; i < n; i++) {
        std::string str;
        int x;
        std::cin >> str >> x;
        if(str[0] == 'A') {
            atk.push_back(x);
        } else {
            def.push_back(x);
        }
    }
    int a = atk.size(), d = def.size();
    for(int i = 0; i < m; i++) {
        int x;
        std::cin >> x;
        me.push_back(x);
    }
    {
        // not attaking enemy
        MCMF<int> graph(n + m + 2);
        int src = n + m, sink = n + m + 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < a; j++) {
                int got = atk[j];
                if(me[i] >= got) {
                    graph.addEdge(i, m + j, 1, -(me[i] - got));
                }
            }
        }
        for(int i = 0; i < m; i++) {
            graph.addEdge(src, i, 1, 0);
        }
        for(int i = 0; i < n; i++) {
            graph.addEdge(m + i, sink, 1, 0);
        }
        graph.mcmf(src, sink, true);
    }
    if(n <= m) {
        // attaking enemy
        MCMF<int> graph(n + m + 3);
        int src = n + m, sink = n + m + 1;
        int special = n + m + 2;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < a; j++) {
                int got = atk[j];
                if(me[i] >= got) {
                    graph.addEdge(i, m + j, 1, -(me[i] - got));
                }
            }
            for(int j = 0; j < d; j++) {
                int got = def[j];
                if(me[i] > got) {
                    graph.addEdge(i, m + a + j, 1, 0);
                }
            }
            graph.addEdge(i, special, 1, -me[i]);
        }
        graph.addEdge(special, sink, m - n, 0);
        for(int i = 0; i < m; i++) {
            graph.addEdge(src, i, 1, 0);
        }
        for(int i = 0; i < n; i++) {
            graph.addEdge(m + i, sink, 1, 0);
        }
        auto ans = graph.mcmf(src, sink);
        if(ans.first == m) {
            haha = std::max(haha, (long long) -ans.second);
        }
    }
    std::cout << haha << '\n';
}