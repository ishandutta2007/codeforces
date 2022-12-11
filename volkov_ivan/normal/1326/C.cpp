#include <bits/stdc++.h>
#define int long long

using namespace std;

const int M = 998244353;

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int lst = 0, res = 1, summ = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x > n - k) {
            summ += x;
            if (lst != 0) res = (res * (i - lst)) % M;
            lst = i;
        }
    }
    cout << summ << ' ' << res << endl;
    return 0;
}