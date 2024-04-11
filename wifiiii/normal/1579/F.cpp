#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        vector<int> a(n), vis(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int f = 0, ans = 0;
        for(int i = 0; i < n; ++i) {
            if(vis[i]) continue;
            int cur = i;
            vector<int> b;
            while(!vis[cur]) {
                vis[cur] = 1;
                b.push_back(a[cur]);
                cur = (cur + d) % n;
            }
            int p = -1;
            for(int j = 0; j < b.size(); ++j) if(b[j] == 0) p = j;
            if(p == -1) {
                f = 1;
                break;
            }
            p -= b.size();
            for(int j = 0; j < b.size(); ++j) {
                if(b[j] == 1) {
                    ans = max(ans, j - p);
                } else {
                    p = j;
                }
            }
        }
        if(f) cout << -1 << endl;
        else cout << ans << endl;
    }
}