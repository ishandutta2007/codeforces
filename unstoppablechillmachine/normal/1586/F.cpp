#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    auto cnt_digits = [](int n, int base) {
        int result = 1;
        while (n >= base) {
            n /= base;
            result++;
        }
        return result;
    };

    auto get_digit = [](int n, int base, int digit) {
        while (digit > 0) {
            n /= base;
            digit--;
        }
        return n % base;
    };

    int cnt = cnt_digits(n - 1, k);
    cout << cnt << '\n';

    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int color = 0;
            while (get_digit(j, k, color) <= get_digit(i, k, color)) {
                color++;
            }
            cout << color + 1 << ' ';
        }
    }
}