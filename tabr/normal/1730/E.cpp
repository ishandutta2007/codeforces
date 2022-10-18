#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

// editorial

struct sieve {
    vector<int> primes;
    vector<bool> is_prime;
    vector<int> min_factor;

    sieve(int MAX = 1 << 20) {
        is_prime = vector<bool>(MAX, true);
        min_factor = vector<int>(MAX);
        is_prime[0] = is_prime[1] = false;
        min_factor[0] = min_factor[1] = 1;
        for (int i = 2; i < MAX; i++) {
            if (!is_prime[i]) {
                continue;
            }
            primes.emplace_back(i);
            min_factor[i] = i;
            if ((long long) i * i >= MAX) {
                continue;
            }
            for (int j = i * i; j < MAX; j += i) {
                if (is_prime[j]) {
                    is_prime[j] = false;
                    min_factor[j] = i;
                }
            }
        }
    }

    vector<pair<int, int>> factor(int n) {
        vector<pair<int, int>> res;
        while (n != 1) {
            int p = min_factor[n];
            res.emplace_back(p, 0);
            while (p == min_factor[n]) {
                n /= p;
                res.back().second++;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> divisor(int n) {
        vector<int> res(1, 1);
        for (const auto& p : factor(n)) {
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
    }

    vector<int> mu_table() {
        vector<int> res(min_factor.size());
        for (int i = 1; i < (int) min_factor.size(); i++) {
            if (i == 1) {
                res[i] = 1;
            } else if ((i / min_factor[i]) % min_factor[i] == 0) {
                res[i] = 0;
            } else {
                res[i] = -res[i / min_factor[i]];
            }
        }
        return res;
    }

    // zeta: add
    // mobius: subtract
    // zeta <-> mobius
    template <typename T>
    void divisor_zeta(vector<T>& a) {
        int n = (int) a.size();
        for (int p : primes) {
            if (p >= n) {
                break;
            }
            for (int i = 1; p * i < n; i++) {
                a[p * i] += a[i];
            }
        }
    }

    template <typename T>
    void divisor_mobius(vector<T>& a) {
        int n = (int) a.size();
        for (int p : primes) {
            if (p >= n) {
                break;
            }
            for (int i = (n - 1) / p; i >= 1; i--) {
                a[p * i] -= a[i];
            }
        }
    }

    template <typename T>
    void multiple_zeta(vector<T>& a) {
        int n = (int) a.size();
        for (int p : primes) {
            if (p >= n) {
                break;
            }
            for (int i = (n - 1) / p; i >= 1; i--) {
                a[i] += a[p * i];
            }
        }
    }

    template <typename T>
    void multiple_mobius(vector<T>& a) {
        int n = (int) a.size();
        for (int p : primes) {
            if (p >= n) {
                break;
            }
            for (int i = 1; p * i < n; i++) {
                a[i] -= a[p * i];
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve si;
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> at(1000010);
        for (int i = 0; i < n; i++) {
            at[a[i]].emplace_back(i);
        }
        vector<int> lge(n, -1);
        vector<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.back()] < a[i]) {
                s.pop_back();
            }
            if (!s.empty()) {
                lge[i] = s.back();
            }
            s.emplace_back(i);
        }
        s.clear();
        vector<int> ll(n, -1);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.back()] >= a[i]) {
                s.pop_back();
            }
            if (!s.empty()) {
                ll[i] = s.back();
            }
            s.emplace_back(i);
        }
        s.clear();
        vector<int> rg(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && a[s.back()] <= a[i]) {
                s.pop_back();
            }
            if (!s.empty()) {
                rg[i] = s.back();
            }
            s.emplace_back(i);
        }
        s.clear();
        vector<int> rl(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && a[s.back()] >= a[i]) {
                s.pop_back();
            }
            if (!s.empty()) {
                rl[i] = s.back();
            }
            s.emplace_back(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int d : si.divisor(a[i])) {
                if (a[i] == d) {
                    continue;
                }
                auto iter = lower_bound(at[d].begin(), at[d].end(), i);
                int r = n;
                if (iter != at[d].end()) {
                    r = *iter;
                }
                int l = -1;
                if (iter != at[d].begin()) {
                    l = *prev(iter);
                }
                if (l != -1) {
                    int low = max(lge[i], ll[l]);
                    int high = min({rg[i], rl[l], r});
                    if (l - low > 0) {
                        ans += max(0LL, (l - low) * 1LL * (high - i));
                    }
                }
                if (r != n) {
                    int low = max(lge[i], ll[r]);
                    int high = min(rg[i], rl[r]);
                    if (i - low > 0) {
                        ans += max(0LL, (i - low) * 1LL * (high - r));
                    }
                }
                debug(i, d, l, r, ans);
            }
        }
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && a[i] == a[j]) {
                j++;
            }
            ans += (j - i) * 1LL * (j - i + 1) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}