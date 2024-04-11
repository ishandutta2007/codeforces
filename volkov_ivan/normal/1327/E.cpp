#include <iostream>
#define int long long

using namespace std;

const int N = 2e5 + 7, M = 998244353;
int poww[N];

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    poww[0] = 1;
    for (int i = 1; i < N; i++) {
        poww[i] = (poww[i - 1] * 10) % M;
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            cout << 10 << endl;
            break;
        }
        int res = (2 * 10 * 9 * poww[n - i - 1]) % M;
        res = (res + (n - i + 1 - 2) * 10 * 9 * 9 * poww[n - i - 2]) % M;
        cout << res << ' ';
    }
    return 0;
}