#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
vector<pair<pair<int, int>, int>> G[maxn], edge;
pair<int, int> dis[maxn];
bool v[maxn], p[maxn];
int con[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y, z; cin >> x >> y >> z;
        G[x].push_back(make_pair(make_pair(y, z), i)); G[y].push_back(make_pair(make_pair(x, z), i));
        edge.push_back(make_pair(make_pair(x, y), z));
    }
    fill(dis, dis + maxn, make_pair(inf, inf));
    dis[1] = make_pair(0, 0);
    priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>> pq;
    pq.push(make_pair(dis[1], make_pair(1, -1)));
    while (pq.size()) {
        pair<pair<int, int>, pair<int, int>> p = pq.top(); pq.pop();
        if (v[p.second.first]) continue;
        v[p.second.first] = true;
        con[p.second.first] = p.second.second;
        for (pair<pair<int, int>, int> e : G[p.second.first]) {
            pair<int, int> tmp = make_pair(p.first.first + 1, p.first.second + (e.first.second ^ 1));
            if (dis[e.first.first] > tmp) {
                dis[e.first.first] = tmp;
                pq.push(make_pair(dis[e.first.first], make_pair(e.first.first, e.second)));
            }
        }
    }
    int cur = n;
    vector<int> path;
    while (con[cur] != -1) {
        path.push_back(con[cur]);
        cur = (edge[con[cur]].first.first == cur ? edge[con[cur]].first.second : edge[con[cur]].first.first);
    } 
    vector<pair<pair<int, int>, int>> ans;
    for (int i : path) {
        p[i] = true;
        if (edge[i].second == 0) ans.push_back(make_pair(edge[i].first, 1));
    }
    for (int i = 0; i < m; ++i) {
        if (p[i]) continue;
        if (edge[i].second == 1) ans.push_back(make_pair(edge[i].first, 0));
    }
    cout << ans.size() << endl;
    for (auto i : ans) cout << i.first.first << ' ' << i.first.second << ' ' << i.second << endl;
    return 0;
}