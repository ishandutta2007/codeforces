#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 5;
string s[maxn];
map<string, int> mp;
int a[maxn], g[maxn], c[maxn];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, m; cin >> n >> k >> m;
    for (int i = 0; i < n; ++i) cin >> s[i], mp[s[i]] = i;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        c[i] = 1e9 + 1;
        while (x--) {
            int p; cin >> p; --p;
            g[p] = i;
            c[i] = min(c[i], a[p]);
        }
    }
    int ans = 0;
    while (m--) {
        string z; cin >> z;
        ans += c[g[mp[z]]];
    }
    cout << ans << endl;
}