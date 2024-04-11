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
        vector<vector<ll>> a(n);
        vector<ll> x(n), y(n);
        for(int i = 0; i < n; ++i) cin >> x[i], --x[i];
        for(int i = 0; i < n; ++i) cin >> y[i];
        for(int i = 0; i < n; ++i) {
            a[x[i]].push_back(y[i]);
        }
        vector<ll> ans(n);
        for(int i = 0; i < n; ++i) {
            if(a[i].empty()) continue;
            sort(a[i].begin(), a[i].end());
            vector<ll> sum {0};
            partial_sum(a[i].begin(), a[i].end(), back_inserter(sum));
            ll tot = accumulate(a[i].begin(), a[i].end(), 0ll);
            for(int j = 1; j <= n; ++j) {
                if(a[i].size() < j) break;
                ans[j - 1] += tot - sum[a[i].size() % j];
            }
        }
        for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }
}