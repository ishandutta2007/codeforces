#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], cnt[maxn];

namespace djs {
    int p[maxn], sz[maxn], mrg;
    void init() { 
        iota(p, p + maxn, 0); 
        fill(sz, sz + maxn, 1);
        mrg = 0;
    }
    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        ++mrg;
        if (sz[x] > sz[y]) swap(x, y);
        sz[y] += sz[x], p[x] = y;
    }
    int size(int x) {
        return sz[find(x)];
    }
}

int diff;

void dec(int x) {
    // printf("dec x = %d\n", x);
    --cnt[x];
    if (cnt[x] == 0) --diff;
}

void inc(int x) {
    // printf("inc x = %d\n", x);
    if (cnt[x] == 0) ++diff;
    ++cnt[x];
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    vector<int> o(n); iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](const int &i, const int &j) { return a[i] < a[j]; });
    djs::init();
    pair<int, int> ans = make_pair(-1, -maxn);
    for (int i = 0; i < n; ++i) {
        int x = o[i];
        inc(djs::size(x));
        if (x - 1 >= 0 && a[x - 1] < a[x]) {
            dec(djs::size(x - 1));
            dec(djs::size(x));
            djs::merge(x - 1, x);
            inc(djs::size(x));
        }
        if (x + 1 < n && a[x + 1] < a[x]) {
            dec(djs::size(x + 1));
            dec(djs::size(x));
            djs::merge(x + 1, x);
            inc(djs::size(x));
        }
        if (diff == 1) ans = max(ans, make_pair(i + 1 - djs::mrg, -a[x] - 1));
    }
    printf("%d\n", -ans.second);
    return 0;
}