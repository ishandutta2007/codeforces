#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve_real(int n) {
    int k = n / 2;
    vector <int> perm(1, k + 1);
    for (int i = 1; i <= k - 1; i++)
        perm.push_back(i);
    for (int i = k + 2; i <= n; i++)
        perm.push_back(i);
    perm.push_back(k);
    vector <pair <int, int>> res;
    for (int i = k + 1; i < n; i++)
        res.push_back({i, 1});
    for (int i = k; i >= 1; i--)
        res.push_back({i, n});
    int sm = 0;
    for (auto elem : res)
        sm += (elem.second - elem.first) * (elem.second - elem.first);
    cout << sm << "\n";
    for (int i = 0; i < n; i++)
        cout << perm[i] << ' ';
    cout << "\n";
    cout << res.size() << "\n";
    for (auto elem : res) {
        cout << elem.first << ' ' << elem.second << "\n";
    }
}

void solve() {
    int n;
    cin >> n;
    if (n >= 4) {
        solve_real(n);
        return;
    }
    int res = 0;
    for (int i = 1; i < n; i++)
        res += (n - i) * (n - i);
    cout << res << "\n";
    for (int i = 1; i < n; i++)
        cout << i + 1 << ' ';
    cout << 1 << "\n";
    cout << n - 1 << "\n";
    for (int i = 1; i < n; i++)
        cout << i << ' ' << n << "\n";
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