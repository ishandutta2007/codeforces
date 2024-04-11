#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], b[maxn], n, m, p;
bool v[maxn];
vector<int> ans;

void solve(const vector<int> &vec, int init) {
    map<int, int> c, t;
    for (int i = 1; i <= m; ++i) ++c[b[i]];
    for (int i = 0; i < m; ++i) --c[vec[i]];
    for (auto it = c.begin(); it != c.end(); ++it) ++t[it->second];
    int maxptr = t.rbegin()->first, minptr = t.begin()->first;
    if (maxptr == 0 && minptr == 0) ans.push_back(init);
    for (int i = m; i < vec.size(); ++i) {
        --t[c[vec[i - m]]]; ++c[vec[i - m]]; ++t[c[vec[i - m]]];
        while (t[maxptr + 1] > 0) ++maxptr;
        while (t[minptr] == 0) ++minptr;
        --t[c[vec[i]]]; --c[vec[i]]; ++t[c[vec[i]]];
        while (t[maxptr] == 0) --maxptr;
        while (t[minptr - 1] > 0) --minptr;
        if (maxptr == 0 && minptr == 0) ans.push_back(init + p * (i + 1 - m));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) if (!v[i]) {
        int now = i;
        vector<int> vec;
        while (now <= n) {
            v[now] = true;
            vec.push_back(a[now]);
            now += p;
        }
        if (vec.size() < m) continue;
        solve(vec, i);
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i : ans) cout << i << ' '; cout << endl;
    return 0;
}