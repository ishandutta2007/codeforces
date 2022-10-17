#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int g = 0;
        for(int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            g = gcd(g, x);
        }
        vector<vector<int>> b;
        for(int i = 0; i < g; ++i) {
            vector<int> c;
            for(int j = i; j < n; j += g) {
                c.push_back(a[j]);
            }
            b.push_back(c);
        }
        ll ans = -1e18;
        for(int i = 0; i < 2; ++i) {
            ll res = 0;
            for(auto c : b) {
                int cnt = 0, mn = 1e9;
                ll sum = 0;
                for(int x : c) {
                    if(x < 0) {
                        cnt += 1;
                    }
                    mn = min(mn, abs(x));
                    sum += abs(x);
                }
                if(cnt % 2 != i) {
                    sum -= 2 * mn;
                }
                res += sum;
            }
            ans = max(ans, res);
        }
        cout << ans << '\n';
    }
}