#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> mp;
        for(int i = 0; i < n; ++i) cin >> a[i], mp[a[i]] += 1;
        int ok = 1;
        for(auto [x, y] : mp) {
            if(y % 2 == 1) {
                ok = 0;
                break;
            }
        }
        if(!ok) {
            cout << -1 << '\n';
            continue;
        }
        vector<pair<int,int>> ans;
        vector<int> sz;
        while(!a.empty()) {
            int p = -1;
            for(int j = n - 2; j >= 0; --j) {
                if(a[j] == a[n - 1]) {
                    p = j;
                    break;
                }
            }
            assert(p != -1);
            int c = 0;
            vector<int> b;
            for(int j = n - 2; j > p; --j) {
                ans.push_back({p + c, a[j]});
                c += 1;
                b.push_back(a[j]);
            }
            a.resize(p);
            for(int x : b) a.push_back(x);
            sz.push_back(b.size() * 2 + 2);
            n = a.size();
        }
        cout << ans.size() << '\n';
        for(auto [x, y] : ans) {
            cout << x << ' ' << y << '\n';
        }
        reverse(sz.begin(), sz.end());
        cout << sz.size() << '\n';
        for(int x : sz) cout << x << ' '; cout << '\n';
    }
}