#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn], fa[maxn], sz[maxn], cnt;
bool v[maxn];
vector<int> pos[maxn];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] & 1) --cnt;
    if (sz[y] & 1) --cnt;
    sz[y] += sz[x];
    fa[x] = y;
    if (sz[y] & 1) ++cnt;
}

int main() {
    int n; scanf("%d", &n);
    vector<int> ds;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ds.push_back(a[i]);
    }
    sort(ds.begin(), ds.end());
    ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 0; i < n; ++i) a[i] = lower_bound(ds.begin(), ds.end(), a[i]) - ds.begin();
    for (int i = 0; i < n; ++i) pos[a[i]].push_back(i);
    for (int i = 0; i < n; ++i) fa[i] = i, sz[i] = 1;
    for (int i = 0; i < (int)ds.size(); ++i) {
        for (int j = 0; j < (int)pos[i].size(); ++j) {
            int x = pos[i][j];
            cnt++;
            if (x > 0 && v[x - 1]) merge(x, x - 1);
            if (x + 1 < n && v[x + 1]) merge(x, x + 1);
            v[x] = true;
        }
        if (i + 1 < (int)ds.size() && cnt != 0) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}