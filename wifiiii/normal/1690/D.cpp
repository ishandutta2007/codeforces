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
        string s;
        cin >> s;
        vector<int> sum(n + 1);
        for(int i = 0; i < n; ++i) sum[i + 1] = sum[i] + (s[i] == 'W');
        int ans = n;
        for(int i = k; i <= n; ++i) {
            ans = min(ans, sum[i] - sum[i - k]);
        }
        cout << ans << '\n';
    }
}