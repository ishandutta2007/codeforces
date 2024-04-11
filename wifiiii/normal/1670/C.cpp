#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for(int i = 0; i < n; ++i) cin >> a[i], --a[i];
        for(int i = 0; i < n; ++i) cin >> b[i], --b[i];
        for(int i = 0; i < n; ++i) cin >> c[i], --c[i];
        vector<int> pos(n);
        for(int i = 0; i < n; ++i) pos[a[i]] = i;
        vector<int> vis(n);
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(vis[i]) continue;
            int p = i, f = 1;
            while(!vis[p]) {
                vis[p] = 1;
                if(c[p] != -1) f = 0;
                p = pos[b[p]];
            }
            if(f && a[i] != b[i]) ++cnt;
        }
        const int mod = 1e9 + 7;
        int ans = 1;
        for(int i = 1; i <= cnt; ++i) ans = ans * 2 % mod;
        cout << ans << '\n';
    }
}