#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7, M = 998244353;
int a[N];
int b[N];
int obr[N];
bool was[N];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        obr[a[i]] = i;
        was[i] = was[i - 1] = 1;
    }
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
        was[obr[b[i]]] = 0;
    }
    int res = 1;
    for (int i = 1; i <= k; i++) {
        int cnt = 0;
        int pos = obr[b[i]];
        was[pos] = 1;
        if (pos != 1 && was[pos - 1]) cnt++;
        if (pos != n && was[pos + 1]) cnt++;
        res *= cnt;
        res %= M;
    }
    cout << res << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}