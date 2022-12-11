#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> k(n);
    for (int i = 0; i < n; i++)
        cin >> k[i];
    sort(k.begin(), k.end());
    vector <int> c(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> c[i];
    int sm = 0;
    for (int elem : k)
        sm += c[elem];
    int best = sm;
    int pos = n - 1;
    for (int i = 1; i <= min(n, m); i++) {
        if (k[pos] >= i) {
            sm -= c[k[pos]];
            sm += c[i];
            best = min(best, sm);
        } else break;
        pos--;
    }
    cout << best << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}