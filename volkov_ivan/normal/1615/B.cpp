#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 2e5 + 7, K = 20;
int pref[K][N];

void init() {
    for (int k = 0; k < K; k++) {
        pref[k][0] = 0;
        for (int n = 1; n < N; n++) {
            pref[k][n] = pref[k][n - 1];
            if (n & (1 << k))
                pref[k][n]++;
        }
    }
}

void solve() {
    int l, r;
    cin >> l >> r;
    int mini = r - l + 1;
    for (int k = 0; k < K; k++) {
        int cur = (r - l + 1) - (pref[k][r] - pref[k][l - 1]);
        mini = min(mini, cur);
    }
    cout << mini << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}