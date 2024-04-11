#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        if(k == 1) {
            cout << (n - 1) / 2 << '\n';
        } else {
            int ans = 0;
            for(int i = 1; i + 1 < n; ++i) {
                if(a[i] > a[i - 1] + a[i + 1]) ++ans;
            }
            cout << ans << '\n';
        }
    }
}