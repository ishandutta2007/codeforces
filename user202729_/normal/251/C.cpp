#include <iostream>
#include <vector>

typedef long long ll;

const ll lcm = 360360; // lcm(1, 2, .., maxk)

int main() {
    ll a, b;
    int k;
    std::cin >> a >> b >> k;
    {
        ll tmp = b - (b % lcm);
        b -= tmp;
        a -= tmp;
    }
    // so b is in [0, lcm)

    std::vector<int> dp; // dp[x] = min number of second needed to
    // transform x to 0
    dp.resize(lcm, 0);
    for (int i = 1; i < lcm; ++i) {
        dp[i] = dp[i-1] + 1;
        for (int k1 = 3; k1 <= k; ++k1) {
            dp[i] = std::min(dp[i], 1 + dp[i - (i % k1)]); // handle case i % k1 == 0
        }
    }

    ll result = 0;
    if (a - (a % lcm) >= b) {
        result = dp[a % lcm];
        a -= a % lcm;
        ll tmp = (b-1) / lcm + 1;//should be 0 or 1
        // reduce a to tmp*lcm (if possible)
        if (a >= tmp * lcm) {
            result +=
            (a/lcm - tmp) // involve that many number of multi-steps
            * (1 + dp[lcm-1]) // each step need that
            ; // does not overflow because lcm is long long
            a = tmp*lcm;
        }
    }

    if (a == b) {
        std::cout << result;
        return 0;
    }
    if (a < b) std::cout << "ERROR1";
    if ((a % lcm) == 0) {
        --a; // note that a != b => a >= b
        ++result; // the only way to decrement a
    }

    dp.clear(); dp.resize(lcm, 2000000000000000000LL); // inf (2*10^18)
    dp[b] = 0;
    for (int i = b+1; i < lcm; ++i) {
        dp[i] = dp[i-1]+1;
        for (int k1 = 3; k1 <= k; ++k1) {
            dp[i] = std::min(dp[i], 1 + dp[i - (i % k1)]);
        }
    }

    std::cout << result + dp.at(a) << "\n";
}