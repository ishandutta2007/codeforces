#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;
int deg[N];
int w[N + 1];

void solve() {
    int n;
    cin >> n;
    int sm = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        deg[i] = 0;
        sm += w[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        deg[v]++;
        deg[u]++;
    }
    vector <int> kek;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < deg[i] - 1; j++)
            kek.push_back(w[i]);
    }
    assert((int) kek.size() == n - 2);
    sort(kek.begin(), kek.end(), greater <int>());
    cout << sm << ' ';
    for (int elem : kek) {
        sm += elem;
        cout << sm << ' ';
    }
    cout << "\n";
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
}