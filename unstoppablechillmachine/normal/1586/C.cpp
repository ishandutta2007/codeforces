#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> c(n + 1, vector<char>(m + 1));
    vector<vector<int>> vl(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            vl[i][j] = !((c[i - 1][j] == '.') || (c[i][j - 1] == '.'));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vl[i][j] += vl[i][j - 1];
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vl[i][j] += vl[i - 1][j];
        }
    }

    auto get_sum = [&](int a, int b, int a2, int b2) {
        return vl[a2][b2] - vl[a - 1][b2] - vl[a2][b - 1] + vl[a - 1][b - 1];
    };

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if (l == r || n == 1) {
            cout << "YES\n";
            continue;
        }
        cout << (get_sum(2, l + 1, n, r) == 0 ? "YES" : "NO") << '\n';
    }

}