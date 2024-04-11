#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 1e6 + 7, M = 1007;
vector <int> num[N];
bool used[2 * M];

void solve() {
    int n;
    cin >> n;
    int a[2 * n];
    for (int i = 0; i < 2 * n; i++)
        cin >> a[i];
    sort(a, a + 2 * n, greater <int>());
    for (int st = 1; st < 2 * n; st++) {
        for (int i = 0; i < 2 * n; i++) {
            used[i] = 0;
            num[a[i]].clear();
        }
        for (int i = 2 * n - 1; i >= 0; i--) {
            num[a[i]].push_back(i);
        }
        vector <pair <int, int>> res;
        int x = a[0] + a[st];
        bool ok = 1;
        for (int i = 0; i < 2 * n; i++) {
            if (used[i])
                continue;
            used[i] = 1;
            num[a[i]].pop_back();
            //cout << i << ' ' << res.size() << endl;
            if (a[i] >= x || num[x - a[i]].empty()) {
                ok = 0;
                break;
            }
            int pos = num[x - a[i]].back();
            num[x - a[i]].pop_back();
            used[pos] = 1;
            res.push_back({a[i], a[pos]});
            x = a[i];
        }
        for (int i = 0; i < 2 * n; i++) {
            num[a[i]].clear();
        }
        if (ok) {
            cout << "YES\n";
            cout << a[0] + a[st] << "\n";
            for (auto elem : res) {
                cout << elem.first << ' ' << elem.second << "\n";
            }
            return;
        }
    }
    cout << "NO\n";
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