#include <bits/stdc++.h>

using namespace std;

int A[100005], B[100005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> A[i];
        for (int i = 1; i <= n; ++i) cin >> B[i];
        vector<int> C[2];
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += B[i];
            C[A[i]].push_back(B[i]);
        }
        sort(C[0].rbegin(), C[0].rend());
        sort(C[1].rbegin(), C[1].rend());
        if (C[0].size() != C[1].size()) {
            for (int i = 0; i < int(C[0].size()) && i < int(C[1].size()); ++i) ans += C[0][i] + C[1][i];
        }
        else {
            for (int i = 0; i < int(C[0].size()); ++i) ans += C[0][i] + C[1][i];
            ans -= min(C[0].back(), C[1].back());
        }
        printf("%lld\n", ans);
    }
    return 0;
}