#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, w;
    cin >> n >> w;
    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater <pair <int, int>>());
    vector <int> res;
    int cur = 0;
    for (auto elem : a) {
        if (cur + elem.first <= w) {
            cur += elem.first;
            res.push_back(elem.second);
        }
    }
    int need = (w + 1) / 2;
    if (cur < need) {
        cout << "-1\n";
        return;
    }
    cout << res.size() << "\n";
    for (int elem : res) {
        cout << elem + 1 << ' ';
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
    for (int i = 0; i < t; i++) solve();
    return 0;
}