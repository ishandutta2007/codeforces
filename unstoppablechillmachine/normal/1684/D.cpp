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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int sum = 0;
        for (auto &x : a) {
            cin >> x;
            sum += x;
        }
        vector<int> srt;
        for (int i = 0; i < n; i++) {
            srt.push_back(a[i] - (n - i - 1));
        }
        sort(srt.rbegin(), srt.rend());
        vector<int> pref(k);
        pref[0] = srt[0];
        for (int i = 1; i < k; i++) {
            pref[i] = pref[i - 1] + srt[i];
        }
        int answer = sum;
        for (int i = 1; i <= k; i++) {
            answer = min(answer, sum - pref[i - 1] - i * (i - 1) / 2);
        }
        cout << answer << '\n';
    }
    return 0;
}