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
    const int MAX = 1000001;
    vector<int> primes;
    vector<int> spf(MAX);
    vector<bool> is_prime(MAX, true);
    is_prime[0] = is_prime[1] = false;
    spf[0] = spf[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (!is_prime[i]) {
            continue;
        }
        primes.emplace_back(i);
        spf[i] = i;
        if (1LL * i * i >= MAX) {
            continue;
        }
        for (int j = i * i; j < MAX; j += i) {
            if (is_prime[j]) {
                is_prime[j] = false;
                spf[j] = i;
            }
        }
    }
    function<vector<pair<int, int>>(int)> factor = [&](int n) {
        vector<pair<int, int>> res;
        while (n != 1) {
            int p = spf[n];
            res.emplace_back(p, 0);
            while (p == spf[n]) {
                n /= p;
                res.back().second++;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    };
    function<vector<int>(int)> divisor = [&](int n) {
        vector<int> res(1, 1);
        vector<pair<int, int>> f = factor(n);
        for (auto p : f) {
            for (int i = (int) res.size() - 1; i >= 0; i--) {
                int c = res[i];
                for (int j = 0; j < p.second; j++) {
                    c *= p.first;
                    res.emplace_back(c);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    };
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(MAX);
    vector<vector<int>> d(MAX);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
        d[a[i]].emplace_back(1);
    }
    sort(a.begin(), a.end());
    for (int i = MAX - 1; i >= 1; i--) {
        if (!b[i]) {
            sort(d[i].begin(), d[i].end());
            for (int j = 1; j < (int) d[i].size(); j++) {
                if (__gcd(d[i][0], d[i][j]) == 1) {
                    b[i] = 1;
                    break;
                }
            }
        }
        if (b[i]) {
            for (int j : divisor(i)) {
                d[j].emplace_back(i / j);
            }
            continue;
        }
    }
    cout << accumulate(b.begin(), b.end(), 0) - n << '\n';
    return 0;
}