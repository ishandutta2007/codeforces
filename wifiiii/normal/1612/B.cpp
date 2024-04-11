#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> ans(n, -1), vis(n + 1);
        vis[a] = vis[b] = 1;
        int j = n - 1;
        for(int i = 1; i < a; ++i) {
            if(vis[i]) continue;
            ans[j--] = i; vis[i] = 1;
        }
        ans[j] = b;
        j = 0;
        for(int i = n; i >= b; --i) {
            if(vis[i]) continue;
            ans[j++] = i; vis[i] = 1;
        }
        ans[j] = a;
        int cur = 1;
        for(int i = 0; i < n; ++i) {
            if(ans[i] != -1) continue;
            while(vis[cur]) ++cur;
            ans[i] = cur; vis[cur] = 1;
        }
        int mn = n, mx = 1;
        for(int i = 0; i < n / 2; ++i) mn = min(mn, ans[i]);
        for(int i = n / 2; i < n; ++i) mx = max(mx, ans[i]);
        if(mx == b && mn == a) {
            for(int i : ans) cout << i << " "; cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}