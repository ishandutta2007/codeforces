#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int s[maxn], d[maxn], c[maxn];
int ans[maxn];
bool v[maxn];
vector<int> ex[maxn];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &s[i], &d[i], &c[i]);
        ex[s[i]].push_back(i);
    }
    fill_n(ans, maxn, -1);
    for (int i = 0; i < m; ++i) ans[d[i]] = m;
    vector<int> z; 
    for (int i = 1; i <= n; ++i) {
        for (int j : ex[i]) z.push_back(j);
        for (int j = 0; j < m; ++j) if (d[j] == i) {
            if (c[j] > 0) return 0 * puts("-1");
        }
        if (ans[i] == -1) {
            int urg = maxn, p = -1;
            for (int j = 0; j < z.size(); ++j) {
                int left = d[z[j]] - i;
                int hv = left - c[z[j]];
                if (hv < 0) return 0 * puts("-1");
                if (hv < urg) urg = hv, p = z[j];
            }
            if (p != -1) ans[i] = p, --c[p];
        }
        vector<int> kz;
        for (int j = 0; j < z.size(); ++j) if (c[z[j]] > 0) kz.push_back(z[j]);
        z = kz;
    }
    for (int i = 1; i <= n; ++i) printf("%d ", ans[i] + 1); puts("");
    return 0;
}