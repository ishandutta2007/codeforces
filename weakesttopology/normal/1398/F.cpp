#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<array<int, 2>> left(n + 1), right(n + 1);
    for (int i = 0; i < n; ++i) {
        for (int t : {0, 1}) {
            if (s[i] == '0' + (t ^ 1)) continue;
            left[i][t] = 1 + (i > 0 ? left[i - 1][t] : 0);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int t : {0, 1}) {
            if (s[i] == '0' + (t ^ 1)) continue;
            right[i][t] = 1 + (i + 1 < n ? right[i + 1][t] : 0);
        }
    }
    for (int x = 1; x <= n; ++x) {
        int ans = 0;
        for (int l = 0; l + x <= n; l += x) {
            bool good = false;
            for (int t : {0, 1}) {
                if (right[l][t] >= x) {
                    ++ans;
                    good = true;
                    break;
                }
            }
            if (good) continue;
            int mx = -1;
            for (int t : {0, 1}) {
                if (left[l + x - 1][t] + right[l + x][t] >= x) {
                    mx = max(left[l + x - 1][t], mx);
                }
            }
            if (mx != -1) l -= mx;
        }
        cout << ans << "\n "[x < n];
    }
    exit(0);
}