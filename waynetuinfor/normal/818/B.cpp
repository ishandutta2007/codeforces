#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int l[maxn], a[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> l[i];
    for (int i = 1; i < m; ++i) {
        int dis = (l[i + 1] - l[i] > 0 ? l[i + 1] - l[i] : l[i + 1] + n - l[i]);
        // cout << dis << endl;
        // dis = (dis + n) % n;
        // if (dis == 0) dis = n;
        if (a[l[i]]) {
            if (dis != a[l[i]]) return cout << "-1\n", 0;
        } else {
            if (v[dis]) return cout << "-1\n", 0;
            else v[dis] = true, a[l[i]] = dis;
        }
    }
    vector<int> em, nt;
    for (int i = 1; i <= n; ++i) if (!a[i]) em.push_back(i);
    for (int i = 1; i <= n; ++i) if (!v[i]) nt.push_back(i);
    for (int i = 0; i < em.size(); ++i) a[em[i]] = nt[i];
    for (int i = 1; i <= n; ++i) cout << a[i] << ' '; cout << endl;
    return 0;
}