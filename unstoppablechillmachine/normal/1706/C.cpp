#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        auto f = [&](int i) {
            return max(0ll, max(a[i - 1] + 1, a[i + 1] + 1) - a[i]);
        };
        int answer = 0;
        if (n & 1) {
            for (int i = 1; i + 1 < n; i += 2) {
                answer += f(i);
            }
        } else {
            vector<int> pref(n / 2), suf(n / 2);
            for (int i = 1; i < n / 2; i++) {
                pref[i] = pref[i - 1] + f(i * 2 - 1);
                suf[i] = suf[i - 1] + f(n - i * 2);
            }
            answer = pref[n / 2 - 1];
            for (int i = 1; i < n / 2; i++) {
                answer = min(answer, pref[n / 2 - 1 - i] + suf[i]);
            }
        }
        cout << answer << '\n';
    }
    return 0;
}