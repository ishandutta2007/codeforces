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
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end(), greater<int>());
        vector<int> sum(n + 1);
        for(int i = 0; i < n; ++i) sum[i + 1] = sum[i] + a[i];
        while(m--) {
            int x;
            cin >> x;
            if(sum.back() < x) cout << -1 << '\n';
            else cout << lower_bound(sum.begin(), sum.end(), x) - sum.begin() << '\n';
        }
    }
}