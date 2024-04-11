#include <bits/stdc++.h>
using namespace std;

int64_t l, r, x, y;
// a * b = x * y
// find factors of x * y


void run_case() {
    cin >> l >> r >> x >> y;
    if(y%x) {
        cout << 0 << "\n";
        return;
    }
    int64_t res = y / x;

    int64_t ans = 0;
    for(int64_t i = 1; i * i <= res; i++) {
        if(res % i == 0) {
            long long a = res / i, b = i;
            // cerr << a << " " << b << "\n";
            if(__gcd(a, b) != 1) continue;
            if(l <= a * x && r >= a * x && l <= b * x && b * x <= r) ans += 1 + (a != b);
        }
    }    

    cout << ans << "\n";
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;

#ifdef RUN_CASE
    cin >> T;
#endif

    for(int test_case = 0; test_case < T; test_case++)
        run_case();
}