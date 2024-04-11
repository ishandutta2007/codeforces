#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve() {
    int n;
    cin >> n;
    bool vis[n];
    for (int i = 0; i < n; i++) vis[i] = 0;
    bool res = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int t = (x + i) % n;
        if (t < 0) t += n;
        if (vis[t]) res = 0;
        vis[t] = 1;
    }
    cout << (res ? "YES" : "NO") << "\n";
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