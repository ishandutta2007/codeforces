#include <bits/stdc++.h>
using namespace std;

int a[1005];
int b[2005];

// in: n, m, graph
// out: match, matched
// vertex cover: (reached[0][left_node] == 0) || (reached[1][right_node] == 1)
// O(E*sqrt(V))
struct BipartiteMatching {
    int n, m;
    vector<vector<int>> graph;
    vector<int> matched, match, edgeview, level;
    vector<int> reached[2];
    BipartiteMatching(int n, int m) : n(n), m(m), graph(n), matched(m, -1),
    match(n, -1) {}
    bool assignLevel() {
        bool reachable = false;
        level.assign(n, -1);
        reached[0].assign(n, 0);
        reached[1].assign(m, 0);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (match[i] == -1) {
                level[i] = 0;
                reached[0][i] = 1;
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (auto adj : graph[cur]) {
                reached[1][adj] = 1;
                auto next = matched[adj];
                if (next == -1) {
                    reachable = true;
                }
                else if (level[next] == -1) {
                    level[next] = level[cur] + 1;
                    reached[0][next] = 1;
                    q.push(next);
                }
            }
        }
        return reachable;
    }
    int findpath(int nod) {
        for (int &i = edgeview[nod]; i < graph[nod].size(); i++) {
            int adj = graph[nod][i];
            int next = matched[adj];
            if (next >= 0 && level[next] != level[nod] + 1) continue;
            if (next == -1 || findpath(next)) {
                match[nod] = adj;
                matched[adj] = nod;
                return 1;
            }
        }
        return 0;
    }
    int solve() {
        int ans = 0;
        while (assignLevel()) {
            edgeview.assign(n, 0);
            for (int i = 0; i < n; i++)
                if (match[i] == -1)
                    ans += findpath(i);
        }
        return ans;
    }
};

vector<int> dist;

int main()
{
    cin.sync_with_stdio(false);
    int n, k, p;
    cin >> n >> k >> p;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> b[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            dist.push_back(abs(a[i] - b[j]) + abs(b[j] - p));
        }
    }

    sort(dist.begin(), dist.end());
    dist.erase(unique(dist.begin(), dist.end()), dist.end());

    int lo = 0, hi = (int)dist.size() - 2, ans = dist.size() - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        BipartiteMatching bm(n, k);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (abs(a[i] - b[j]) + abs(b[j] - p) <= dist[mid]) bm.graph[i].push_back(j);
            }
        }

        if (bm.solve() == n)
        {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    printf("%d\n", dist[ans]);
}