#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
        int a;
        cin >> a;
        if (a == 1)
            cout << 0 << endl;
        else
            cout << 1 << endl;
        return 0;
    }
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];
    int ans = 0;
    rep(j, 0, m) {
        map<int, int> mp;
        rep(i, 0, n) {
            if (a[i][j] % m == (j + 1) % m && a[i][j] <= n * m) {
                int b;
                b = (a[i][j] - 1) / m;
                mp[(i - b + n) % n]++;
            }
        }
        int cnt = n;
        for (auto x : mp) {
            cnt = min(cnt, x.first + n - x.second);
        }
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}