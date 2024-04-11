#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<bool> used(n, false);
        vector<int> c(1, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int best = -1, id = -1;
            for (int j = 0; j < n; j++) {
                if (used[j]) {
                    continue;
                }
                if (__gcd(a[j], c.back()) > best) {
                    best = __gcd(a[j], c.back());
                    id = j;
                }
            }
            c.push_back(best);
            ans.push_back(a[id]);
            used[id] = true;
        }
        for (int i = 0; i < (int) ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}