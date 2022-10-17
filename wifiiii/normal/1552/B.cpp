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
        vector<vector<int>> a(n, vector<int>(5));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 5; ++j) {
                cin >> a[i][j];
            }
        }
        auto cmp = [&](int i, int j) {
            int cnt = 0;
            for(int k = 0; k < 5; ++k) {
                cnt += a[i][k] < a[j][k];
            }
            return cnt <= 2;
        };
        int mx = 0;
        for(int i = 1; i < n; ++i) {
            if(cmp(mx, i)) mx = i;
        }
        int ok = 1;
        for(int i = 0; i < n; ++i) {
            if(i == mx) continue;
            if(cmp(mx, i)) ok = 0;
        }
        if(ok) cout << 1 + mx << '\n';
        else cout << -1 << '\n';
    }
}