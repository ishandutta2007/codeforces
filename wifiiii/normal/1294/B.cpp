#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int,int>> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
        sort(a.begin(), a.end());
        int x = 0, y = 0, ok = 1;
        string ans;
        for(auto [xx, yy] : a) {
            assert(xx >= x);
            if(yy < y) {
                ok = 0;
                break;
            }
            while(x < xx) {
                ans += 'R';
                x += 1;
            }
            while(y < yy) {
                ans += 'U';
                y += 1;
            }
        }
        if(ok) {
            cout << "YES" << endl;
            cout << ans << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}