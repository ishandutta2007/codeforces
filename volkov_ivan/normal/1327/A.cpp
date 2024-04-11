#include <iostream>
#define int long long

using namespace std;

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n, k;
        cin >> n >> k;
        int res = (1 + (2 * k - 1)) * k / 2;
        if (res % 2 == n % 2 && res <= n) {
            cout << "YES\n";
        } else {
            cout << "NO\n"; 
        }
    }
    return 0;
}