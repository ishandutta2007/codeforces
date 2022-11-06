#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int x[maxn], y[maxn], cnt[maxn], cc[maxn], fw[maxn];

void add(int x, int v) {
    for (int i = x + 1; i < maxn; i += i & -i)
        fw[i] += v;
}

int query(int x) {
    int res = 0;
    for (int i = x + 1; i > 0; i -= i & -i)
        res += fw[i];
    return res;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
    vector<int> dx(x, x + n), dy(y, y + n);

    sort(dx.begin(), dx.end());
    sort(dy.begin(), dy.end());
    dx.resize(unique(dx.begin(), dx.end()) - dx.begin());
    dy.resize(unique(dy.begin(), dy.end()) - dy.begin());

    for (int i = 0; i < n; ++i) {
        x[i] = lower_bound(dx.begin(), dx.end(), x[i]) - dx.begin();
        y[i] = lower_bound(dy.begin(), dy.end(), y[i]) - dy.begin();
        ++cc[x[i]];
    }

    long long ans = 0;

    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    sort(v.begin(), v.end(), [&](int i, int j) {
        return y[i] > y[j];
    });

    int kind = 0;
    // set<tuple<int, int, int>> seg;
    long long dis = 0;

    set<int> alive;

    for (int i = (int)dy.size() - 1, j = 0; i >= 0; --i) {
        vector<int> news, adds;
        while (j < n && y[v[j]] == i) {
            if (cnt[x[v[j]]] == 0) {
                ++kind;
                cnt[x[v[j]]]++;
                adds.push_back(x[v[j]]);
            }
            news.push_back(x[v[j]]);
            ++j;
        }
        sort(news.begin(), news.end());
        news.resize(unique(news.begin(), news.end()) - news.begin());
        
        if (news.size() && news[0] > 0) {
            int r = query(news[0] - 1);
            ans -= r * 1ll * (r + 1) / 2;
        }
        if (news.size()) {
            int r = query(dx.size()) - query(news.back());
            ans -= r * 1ll * (r + 1) / 2;
        }
        for (int k = 1; k < (int)news.size(); ++k) {
            int r = query(news[k] - 1) - query(news[k - 1]);
            // printf("r = %d\n", r);
            ans -= r * 1ll * (r + 1) / 2;
        }
        for (int k : adds) add(k, 1);
        // printf("kind = %d\n", kind);
        ans += kind * 1ll * (kind + 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}