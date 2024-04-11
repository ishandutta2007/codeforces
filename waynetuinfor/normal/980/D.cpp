#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5;
vector<int> pr;
bool v[maxn];
int a[maxn], c[maxn], ans[maxn];
pair<int, vector<int>> p[maxn];

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) pr.push_back(i);
        for (int j = 0; i * pr[j] < maxn; ++j) {
            v[i * pr[j]] = true;
            if (i % pr[j] == 0) break;
        }
    }
}

int main() {
    sieve();
    int n; scanf("%d", &n);
    vector<pair<int, vector<int>>> ds;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        int t = abs(a[i]);
        if (a[i] > 0) p[i].first = 1;
        else p[i].first = -1;
        for (int j = 0; j < pr.size() && t > 1; ++j) {
            int c = 0;
            while (t % pr[j] == 0) t /= pr[j], c ^= 1;
            if (c) p[i].second.push_back(pr[j]);
        }
        if (t > 1) p[i].second.push_back(t);
        ds.push_back(p[i]);
    }
    sort(ds.begin(), ds.end()), ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 0; i < n; ++i) c[i] = lower_bound(ds.begin(), ds.end(), p[i]) - ds.begin();
    for (int l = 0; l < n; ++l) {
        memset(v, false, sizeof(v));
        int z = 0, k = 0;
        for (int r = l; r < n; ++r) {
            if (a[r] != 0 && !v[c[r]]) ++z, v[c[r]] = true;
            ++ans[max(1, z)];
        }
    }
    for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
    puts("");
}