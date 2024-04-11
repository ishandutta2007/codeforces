#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, l;

vector<int> p;

const int N = 100005;
int x[N], d[N], t[N], q[N], ord[N];

vector<pair<int, int> > edge[N << 1];
vector<int> mark[N << 1];

int dis[N << 1];

pair<int, int> fa[N << 1];

int main() {
    scanf("%d%d", &n, &l);
    p.push_back(0);
    p.push_back(l);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", x + i, d + i, t + i, q + i);
        ord[i] = cnt++;
        if (x[i] - q[i] < 0) {
            --n, --i;
            continue;
        }
        p.push_back(x[i] - q[i]);
        p.push_back(x[i] + d[i]);
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    for (int i = 0; i + 1 < (int)p.size(); ++i) {
        edge[i].push_back(make_pair(i + 1, p[i + 1] - p[i]));
        mark[i].push_back(-1);
        edge[i + 1].push_back(make_pair(i, p[i + 1] - p[i]));
        mark[i + 1].push_back(-1);
    }
    for (int i = 0; i < n; ++i) {
        int st = lower_bound(p.begin(), p.end(), x[i] - q[i]) - p.begin(),
            ed = lower_bound(p.begin(), p.end(), x[i] + d[i]) - p.begin();
        edge[st].push_back(make_pair(ed, t[i] + q[i]));
        mark[st].push_back(ord[i]);
    }
    priority_queue<pair<int, int> > heap;
    int m = p.size();
    for (int i = 0; i < m; ++i) {
        dis[i] = l + 1;
    }
    dis[0] = 0;
    heap.push(make_pair(0, 0));
    while (heap.size()) {
        int u = heap.top().second, d = -heap.top().first;
        heap.pop();
        if (d != dis[u]) {
            continue;
        }
        for (int i = 0; i < (int)edge[u].size(); ++i) {
            int nd = d + edge[u][i].second, v = edge[u][i].first;
            if (dis[v] > nd) {
                dis[v] = nd;
                fa[v] = make_pair(u, mark[u][i]);
                heap.push(make_pair(-nd, v));
            }
        }
    }
    printf("%d\n", dis[p.size() - 1]);
    vector<int> ans;
    int u = m - 1;
    while (u) {
        int t = fa[u].second, v = fa[u].first;
        if (t != -1) {
            ans.push_back(t);
        }
        u = v;
    }
    printf("%d\n", (int)ans.size());
    if (ans.size()) {
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < (int)ans.size(); ++i) {
            printf("%d\n", ans[i] + 1);
        }
    }
    return 0;
}