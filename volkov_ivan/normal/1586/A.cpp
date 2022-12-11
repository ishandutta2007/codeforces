#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int W = 107 * 207;
bool ispr[W];

void init() {
     memset(ispr, 1, sizeof(ispr));
     ispr[1] = 0;
     for (int i = 2; i < W; i++) {
         if (ispr[i]) {
             for (int j = i * i; j < W; j += i) {
                 ispr[j] = 0;
             }
         }
     }
}

void solve() {
    int n;
    cin >> n;
    int a[n + 1];
    int sm = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sm += a[i];
    }
    if (!ispr[sm]) {
        cout << n << "\n";
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!ispr[sm - a[i]]) {
            cout << n - 1 << "\n";
            for (int j = 1; j <= n; j++) {
                if (j != i)
                    cout << j << ' ';
            }
            cout << "\n";
            return;
        }
    }
    assert(0);
}

signed main() {
    init();
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}