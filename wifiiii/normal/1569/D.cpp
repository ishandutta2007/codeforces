#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        map<int, int> mx, my, cx, cy;
        map<pair<int,int>, int> qwqx, qwqy;
        vector<int> vx, vy;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            vx.push_back(x);
            mx[x]++;
        }
        for(int i = 0; i < m; ++i) {
            int y;
            cin >> y;
            vy.push_back(y);
            my[y]++;
        }
        vx.push_back(2e9);
        vy.push_back(2e9);
        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());
        ll ans = 0;
        int tx = 0, ty = 0;
        for(int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            if(mx.count(x) && my.count(y)) continue;
            if(mx.count(x)) {
                int p = upper_bound(vy.begin(), vy.end(), y) - vy.begin();
                ans += cx[p] - qwqx[{x, p}];
                qwqx[{x, p}]++;
                cx[p]++;
            } else {
                int p = upper_bound(vx.begin(), vx.end(), x) - vx.begin();
                ans += cy[p] - qwqy[{y, p}];
                qwqy[{y, p}]++;
                cy[p]++;
            }
        }
        cout << ans << '\n';
    }
}