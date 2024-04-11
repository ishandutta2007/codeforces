#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        // n = 1
        vector<int> a(m);
        for(int i = 0; i < m; ++i) cin >> a[i];
        vector<int> sa = a;
        sort(sa.begin(), sa.end());
        vector<int> vis(m);
        int ans = 0;
        for(int i : a) {
            int pos = -1;
            for(int j = m - 1; j >= 0; --j) {
                if(vis[j]) continue;
                if(sa[j] == i) {
                    pos = j;
                    break;
                }
            }
            vis[pos] = 1;
            for(int j = 0; j < pos; ++j) {
                ans += vis[j];
            }
        }
        cout << ans << '\n';
    }
}