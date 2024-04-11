#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    // 1 2 1 1
    // 1011 & 0100
    // 1011 = [0,1,0,0]
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<int> aa(a.begin(), a.end());
        sort(aa.begin(), aa.end());
        aa.resize(unique(aa.begin(), aa.end()) - aa.begin());
        auto f = [&](int x) {
            return lower_bound(aa.begin(), aa.end(), x) - aa.begin();
        };
        vector<vector<int>> pos(aa.size());
        for(int i = 0; i < n; ++i) {
            pos[f(a[i])].push_back(i);
        }
        ll ans = 0;
        for(int i = 0; i < aa.size(); ++i) {
            vector<int> b;
            int lst = 0;
            for(int j : pos[i]) {
                b.push_back(j - lst);
                lst = j;
            }
            b.push_back(n - lst);
            ll s1 = 0, s2 = 0;
            for(int j = 2; j < b.size(); ++j) {
                s1 += b[j - 2];
                s2 += s1 + 1;
                ans += s2 * (n - s1 - b[j-1]);
            }
        }
        cout << ans << '\n';
    }
}