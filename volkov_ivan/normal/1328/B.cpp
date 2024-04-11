#include <iostream>
#define int long long

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        int fi = -1, se = -1;
        for (int a = n - 2; a >= 0; a--) {
            int now = n - a - 1;
            if (k > now) {
                k -= now;
            } else {
                fi = a;
                se = n - k;
                break;
            }
        }
        //cout << fi << ' ' << se << endl;
        for (int j = 0; j < n; j++) {
            if (j == fi || j == se) cout << "b";
            else cout << "a";
        }
        cout << "\n";
    }
    return 0;
}