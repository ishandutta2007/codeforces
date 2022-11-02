#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int M = 100005;

int n, m;
pair<int, int> pos[M];
vector<pair<int, int> > edge[2];
vector<int> num[2];

const int N = 1005;

int fa[N];

int cnt[2];
vector<int> choose[2];

void reset() {
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
    }
    choose[0].clear(), choose[1].clear();
    cnt[0] = cnt[1] = 0;
}

int find(int u) {
    return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
    fa[u] = v;
}

void cover(vector<int> c) {
    for (int i = 0; i < (int)c.size(); ++i) {
        pair<int, int> e = edge[pos[c[i]].first][pos[c[i]].second];
        merge(find(e.first), find(e.second));
    }
}

bool addedge(int c) {
    while (cnt[c] < (int)edge[c].size()) {
        int u = edge[c][cnt[c]].first,
            v = edge[c][cnt[c]].second;
        ++cnt[c];
        if (find(u) != find(v)) {
            choose[c].push_back(num[c][cnt[c] - 1]);
            merge(find(u), find(v));
            return true;
        }
    }
    return false;
}

bool connect() {
    for (int i = 0; i < n; ++i) {
        if (find(i) != find(0)) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    if (n % 2 != 1) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        char col[2];
        scanf("%d%d%s", &u, &v, col);
        --u, --v;
        int c = col[0] == 'S';
        edge[c].push_back(make_pair(u, v));
        num[c].push_back(i);
        pos[i] = make_pair(c, edge[c].size() - 1);
    }
    reset();
    while (addedge(0)) {
        continue;
    }
    while (addedge(1)) {
        continue;
    }
    if (!connect()) {
        printf("-1\n");
        return 0;
    }
    vector<int> tmp[2];
    tmp[1] = choose[1];
    reset();
    cover(tmp[1]);
    while (addedge(1)) {
        continue;
    }
    while (addedge(0)) {
        continue;
    }
    tmp[0] = choose[0];
    reset();
    cover(tmp[0]), cover(tmp[1]);
    choose[0] = tmp[0], choose[1] = tmp[1];
    while (true) {
        if (!addedge(choose[0].size() > choose[1].size())) {
            break;
        }
    }
    if (choose[0].size() != choose[1].size() || !connect()) {
        printf("-1\n");
    } else {
        printf("%d\n", n - 1);
        for (int i = 0; i < (int)choose[0].size(); ++i) {
            printf("%d ", choose[0][i] + 1);
        }
        for (int i = 0; i < (int)choose[1].size(); ++i) {
            printf("%d%c", choose[1][i] + 1, i == (int)choose[1].size() - 1 ? '\n' : ' ');
        }
    }
    return 0;
}