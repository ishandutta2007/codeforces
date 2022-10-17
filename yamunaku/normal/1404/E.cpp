//
// Created by yamunaku on 2020/08/27.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

template<typename flow_t>
struct Dinic {
    const flow_t INF;

    struct edge {
        int to;
        flow_t cap;
        int rev;
        bool isrev;
        int idx;
    };

    vector<vector<edge> > graph;
    vector<int> min_cost, iter;

    Dinic(int V) : INF(numeric_limits<flow_t>::max()), graph(V) {}

    void add_edge(int from, int to, flow_t cap, int idx = -1) {
        graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false, idx});
        graph[to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1, true, idx});
    }

    bool bfs(int s, int t) {
        min_cost.assign(graph.size(), -1);
        queue<int> que;
        min_cost[s] = 0;
        que.push(s);
        while (!que.empty() && min_cost[t] == -1) {
            int p = que.front();
            que.pop();
            for (auto &e : graph[p]) {
                if (e.cap > 0 && min_cost[e.to] == -1) {
                    min_cost[e.to] = min_cost[p] + 1;
                    que.push(e.to);
                }
            }
        }
        return min_cost[t] != -1;
    }

    flow_t dfs(int idx, const int t, flow_t flow) {
        if (idx == t) return flow;
        for (int &i = iter[idx]; i < graph[idx].size(); i++) {
            edge &e = graph[idx][i];
            if (e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
                flow_t d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow_t max_flow(int s, int t) {
        flow_t flow = 0;
        while (bfs(s, t)) {
            iter.assign(graph.size(), 0);
            flow_t f = 0;
            while ((f = dfs(s, t, INF)) > 0) flow += f;
        }
        return flow;
    }

    void output() {
        for (int i = 0; i < graph.size(); i++) {
            for (auto &e : graph[i]) {
                if (e.isrev) continue;
                auto &rev_e = graph[e.to][e.rev];
                cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
            }
        }
    }
};

int main() {
    CFS;
    int h, w;
    cin >> h >> w;
    vector<string> f(h);
    rep(i, h) cin >> f[i];

    Dinic<int> dn(h * w + 2);
    int s = h * w, t = s + 1;
    rep(i, h) {
        rep(j, w) {
            if (f[i][j] == '#') {
                if (i == 0) {
                    dn.add_edge(s, i * w + j, 1);
                } else {
                    if (f[i - 1][j] != '#') {
                        dn.add_edge(s, i * w + j, 1);
                    }
                }
                if (j == 0) {
                    dn.add_edge(i * w + j, t, 1);
                } else {
                    if (f[i][j - 1] != '#') {
                        dn.add_edge(i * w + j, t, 1);
                    }
                }
                if (i < h - 1) {
                    if (f[i + 1][j] == '#') {
                        dn.add_edge(i * w + j, (i + 1) * w + j, 1);
                        dn.add_edge((i + 1) * w + j, i * w + j, 1);
                    } else {
                        dn.add_edge(s, i * w + j, 1);
                    }
                } else {
                    dn.add_edge(s, i * w + j, 1);
                }
                if (j < w - 1) {
                    if (f[i][j + 1] == '#') {
                        dn.add_edge(i * w + j, i * w + j + 1, 1);
                        dn.add_edge(i * w + j + 1, i * w + j, 1);
                    } else {
                        dn.add_edge(i * w + j, t, 1);
                    }
                } else {
                    dn.add_edge(i * w + j, t, 1);
                }
            }
        }
    }
    cout << dn.max_flow(s, t) / 2 << endl;
    return 0;
}