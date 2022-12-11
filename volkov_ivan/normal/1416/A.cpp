#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 3e5 + 7;
int a[N];
int ans[N];
vector <int> pos[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans[i] = N;
        pos[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        pos[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (pos[i].empty()) continue;
        int maxi = 0, lst = 0;
        for (int elem : pos[i]) {
            maxi = max(maxi, elem - lst);
            lst = elem;
        }
        maxi = max(maxi, n + 1 - lst);
        ans[maxi] = min(ans[maxi], i);
    }
    for (int i = 2; i <= n; i++) ans[i] = min(ans[i], ans[i - 1]);
    for (int i = 1; i <= n; i++) {
        if (ans[i] == N) ans[i] = -1;
        cout << ans[i] << ' ';
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