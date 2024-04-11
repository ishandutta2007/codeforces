#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int a, b, k;
        cin >> a >> b >> k;
        int x = 0, y = 0;
        if (k == 1) {
            if (a != b && (a % b == 0 || b % a == 0)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO "<< '\n';
            }
            continue;
        }
        for (int i = 2; i <= max(a, b); i++) {
            while (a % i == 0) {
                a /= i;
                x++;
            }
            while (b % i == 0) {
                b /= i;
                y++;
            }
            if (i * i > max(a, b)) {
                if (a > 1) {
                    x++;
                }
                if (b > 1) {
                    y++;
                }
                break;
            }
        }
        if (x + y >= k) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}