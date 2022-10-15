#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> c(N);
    for (int i = 0; i < N; ++i) {
        cin >> c[i];
    }
    long long ans = 0;
    for (int l = 1; l < N; l += 2) {
        long long sum = 0;
        long long pref = 0;
        for (int r = l + 1; r + 1 < N; r += 2) {
            pref = max(pref, -(sum - c[r - 1]));
            sum += -c[r - 1] + c[r];
            if (c[l - 1] >= pref) {
                if (c[r + 1] >= (sum + pref)) {
                    ans += min(c[l - 1] - pref, c[r + 1] - (sum + pref));
                    if (pref > 0 && sum + pref > 0) ++ans;
                }
            }
        }
    }
    for (int i = 0; i + 1 < N; i += 2) {
        ans += min(c[i], c[i + 1]);
    }
    cout << ans << '\n';
    exit(0);
}