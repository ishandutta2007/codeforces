#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int d = 0, k = 0;
        map<pair<int, int>, int> dp;
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            if(s[i] == 'D') ++d;
            else ++k;
            
            int g = __gcd(d, k);
            int nd = d / g, nk = k / g;
            ans[i] = dp[make_pair(nd, nk)] + 1;
            dp[make_pair(nd, nk)] = ans[i];
        }
        for(int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n"; 
    }
}