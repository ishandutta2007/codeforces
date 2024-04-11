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
        vector<bool> used(n + 1);
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        reverse(a.begin(), a.end());
        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (!used[a[i]]) {
                used[a[i]] = true;
                answer++;
            } else {
                break;
            }
        }
        cout << n - answer << '\n';
    }
    return 0;
}