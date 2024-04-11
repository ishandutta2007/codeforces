#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;

struct edge { int from, to, cap; edge *reverse; };
 
vector<edge*> adj[N];
int n;
 
void add_edge(int u, int v, int w) {
    edge *forwards = new edge{u, v, w};
    edge *backwards = new edge{v, u, 0};
    forwards->reverse = backwards;
    backwards->reverse = forwards;
    adj[u].push_back(forwards);
    adj[v].push_back(backwards);
}
 
int level[N];
 
bool bfs() {
    fill(level, level + n, -1);
 
    queue<int> node_q;
    node_q.push(0);
    level[0] = 0;
 
    while (!node_q.empty()) {
        int u = node_q.front(); node_q.pop();
        for (auto e : adj[u]) {
            if (e->cap && level[e->to] == -1) {
                level[e->to] = level[u] + 1;
                node_q.push(e->to);
 
                if (e->to == n - 1) return true;
            }
        }
    }
 
    return false;
}
 
int ptr[N];
 
int dfs(int u, int flow) {
    if (u == n - 1) return flow;
 
    int sent = 0;
    while (flow && ptr[u] < (int) adj[u].size()) {
        auto e = adj[u][ptr[u]++];
        if (e->cap && level[e->to] == level[u] + 1) {
            int pushed = dfs(e->to, min(flow, e->cap));
            sent += pushed, flow -= pushed;
            e->cap -= pushed, e->reverse->cap += pushed;
        }
    }
 
    return sent;
}
 
int max_flow() {
    int answer = 0;
    while (bfs()) {
        fill(ptr, ptr + n, 0);
        answer += dfs(0, INT_MAX);
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    ::n = n + 2;

    vector<long long> t(n);
    for (auto &i : t) cin >> i;

    int required_flow = 0;
    for (int i = 0; i < n; ++i) {
        if (3 * t[i] <= m) add_edge(0, 1 + i, 1);
        else add_edge(1 + i, n + 1, 1), ++required_flow;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (3 * t[i] <= m && 3 * t[j] > m && t[i] + 2 * t[j] <= m && t[j] % t[i] == 0) {
                add_edge(1 + i, 1 + j, 1);
            }
        }
    }

    if (max_flow() != required_flow) {
        cout << -1 << "\n";
        exit(0);
    }

    cout << n - required_flow << "\n";

    for (int i = 0; i < n; ++i) {
        if (3 * t[i] <= m) {
            bool matched = false;
            for (auto e : adj[i + 1]) {
                if (e->to && !e->cap) {
                    matched = true;
                    cout << t[e->to - 1] + t[i] << " " << t[i] + 2 * t[e->to - 1] << "\n";
                }
            }
            if (!matched)
                cout << 2 * t[i] << " " << 3 * t[i] << "\n";
        }
    }
}