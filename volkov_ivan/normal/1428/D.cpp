#include <bits/stdc++.h>
//#define int long long

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    vector <int> res[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector <int> free_1, free_else;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) continue;
        if (a[i] == 1) {
            res[i].push_back(n - i - 1);
            free_1.push_back(i);
            continue;
        }
        if (a[i] == 2) {
            if (free_1.empty()) {
                cout << -1 << "\n";
                return 0;
            }
            int x = free_1.back();
            free_1.pop_back();
            res[i].push_back(res[x][0]);
            free_else.push_back(i);
            continue;
        }
        if (free_1.empty() && free_else.empty()) {
            cout << -1 << "\n";
            return 0;
        }
        int x;
        if (!free_else.empty()) {
            x = free_else.back();
            free_else.pop_back();
        } else {
            x = free_1.back();
            free_1.pop_back();
        }
        res[i].push_back(n - i - 1);
        res[x].push_back(n - i - 1);
        free_else.push_back(i);
    }
    vector <pair <int, int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j : res[i]) {
            ans.emplace_back(n - j, i + 1);
        }
    }
    cout << ans.size() << "\n";
    for (auto elem : ans) {
        cout << elem.first << ' ' << elem.second << "\n";
    }
    return 0;
}