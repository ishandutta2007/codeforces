#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int d[maxn], a[maxn], n, m;

bool check(int tg) {
    vector<int> dl(maxn, 0);
    for (int i = tg; i >= 1; --i) dl[d[i]] = max(dl[d[i]], i);
    for (int i = 1; i <= m; ++i) if (!dl[i]) return false;
    vector<int> ds;
    for (int i = 1; i <= m; ++i) ds.push_back(i);
    sort(ds.begin(), ds.end(), [&](const int& a, const int& b) { return dl[a] < dl[b]; }); 
    int has = 0, pv = 0;
    for (int i : ds) {
        has += dl[i] - pv;
        if (has < a[i] + 1) return false;
        has -= a[i] + 1;
        pv = dl[i];
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    for (int i = 1; i <= m; ++i) cin >> a[i];
    int bit = 1, ans = n + 1; while (bit <= n) bit <<= 1;
    while (bit >>= 1) if (ans - bit >= 0) if (check(ans - bit)) ans -= bit;
    if (ans == n + 1) ans = -1;
    cout << ans << endl;
    return 0;
}