#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
int a[maxn], t[maxn], pos[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i < n; ++i) a[i] = 1, t[i] = n - i, pos[a[i]] = i;
    pos[0] = n;
    set<int> s; s.insert(1), s.insert(0);
    for (int j = 0; j < k; ++j) {
        vector<int> c(maxn);
        vector<int> na(a, a + maxn);
        for (int i = 1; i <= n; ++i) {
            int to = t[i] - a[i];
            auto it = --(s.upper_bound(to));
            c[i] = pos[*it];
            na[i] = na[i] + a[c[i]];
        }
        set<int> ns;
        for (int i = 1; i <= n; ++i) ns.insert(na[i]);
        for (int i = 1; i <= n; ++i) a[i] = na[i], pos[a[i]] = i;
        swap(ns, s);
        for (int i = 1; i <= n; ++i) cout << c[i] << ' '; cout << endl;
    }
    return 0;
}