#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

const int mod = 998244353;
void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> answer(n + 1), dp1(n + 1), dp2(n + 1);
    dp1[0] = 1;
    for (int i = 0; i < 700; i++) {
        fill(dp2.begin(), dp2.end(), 0);
        for (int j = 0; j < n; j++) {
            if (j + k + i <= n) {
                add(dp2[j + k + i], dp1[j]);
            }
        }

        for (int j = 1; j <= n; j++) {
            if (j - k - i >= 0) {
                add(dp2[j], dp2[j - k - i]);
            }
        }

        for (int j = 0; j <= n; j++) {
            add(answer[j], dp2[j]);
        }
        dp1.swap(dp2);
    }

    for (int i = 1; i <= n; i++) {
        cout << answer[i] << ' ';
    }
    cout << '\n';
    return 0;
}