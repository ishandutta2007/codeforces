#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005, Q = 100005;

vector<pair<int, int> > cedge[N];

int u[Q], v[Q], ans[Q];

map<pair<int, int>, int> anss;

int stamp, vis[N], fa[N];

int find(int u) {
    return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
    fa[u] = v;
}

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        --a, --b, --c;
        cedge[c].push_back(make_pair(a, b));
    } 
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", u + i, v + i);
        --u[i], --v[i];
        ans[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        if (cedge[i].size() == 0) {
            continue;
        }
        vector<int> vs;
        for (int j = 0; j < (int)cedge[i].size(); ++j) {
            vs.push_back(cedge[i][j].first);
            vs.push_back(cedge[i][j].second);
        }
        sort(vs.begin(), vs.end());
        vs.erase(unique(vs.begin(), vs.end()), vs.end());
        ++stamp;
        for (int j = 0; j < (int)vs.size(); ++j) {
            int u = vs[j];
            fa[u] = u;
            vis[u] = stamp;
        }
        for (int j = 0; j < (int)cedge[i].size(); ++j) {
            int u = cedge[i][j].first, v = cedge[i][j].second;
            if (find(u) != find(v)) {
                merge(find(u), find(v));
            }
        }
        if ((long long)vs.size() * vs.size() > n) {
            for (int i = 0; i < q; ++i) {
                if (vis[u[i]] == stamp && vis[v[i]] == stamp) {
                    ans[i] += (find(u[i]) == find(v[i]));
                }
            }
        } else {
            for (int i = 0; i < (int)vs.size(); ++i) {
                for (int j = i + 1; j < (int)vs.size(); ++j) {
                    if (find(vs[i]) == find(vs[j])) {
                        ++anss[make_pair(vs[i], vs[j])];
                        ++anss[make_pair(vs[j], vs[i])];
                    }
                }
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i] + anss[make_pair(u[i], v[i])]);
    }
    return 0;
}