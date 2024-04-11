#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) cin >> a[i][j];
        auto b = a;
        for(int i = 0; i < n; ++i) sort(b[i].begin(), b[i].end());
        int cnt = 0;
        vector<int> p;
        for(int i = 0; i < m; ++i) {
            int f = 0;
            for(int j = 0; j < n; ++j) {
                if(b[j][i] != a[j][i]) {
                    f = 1;
                }
            }
            if(f) {
                cnt += 1;
                p.push_back(i);
            }
        }
        if(cnt == 0) {
            cout << 1 << ' ' << 1 << '\n';
        } else if(cnt == 2) {
            int ok = 1;
            for(int i = 0; i < n; ++i) {
                swap(a[i][p[0]], a[i][p[1]]);
                if(!is_sorted(a[i].begin(), a[i].end())) {
                    ok = 0;
                }
            }
            if(ok == 0) cout << -1 << '\n';
            else cout << p[0] + 1 << ' ' << p[1] + 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}