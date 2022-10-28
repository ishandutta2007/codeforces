#include <bits/stdc++.h>
using namespace std;

long long pow(long long b, long long e, long long m) {
    long long r = 1;
    b %= m;
    while (e > 0) {
        if (e % 2 == 1) {
            r = (__int128) r * b % m;
        }
        b = (__int128) b * b % m;
        e /= 2;
    }
    return r;
}

long long pow(long long b, long long e) {
    long long r = 1;
    while (e > 0) {
        if (e % 2 == 1) {
            r = (__int128) r * b <= LLONG_MAX ? r * b : LLONG_MAX;
        }
        b = (__int128) b * b <= LLONG_MAX ? b * b : LLONG_MAX;
        e /= 2;
    }
    return r;
}

bool check_composite(long long n, long long a, long long d, int s) {
    long long x = pow(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (__int128) x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool miller_rabin(long long x) {
    int r = 0;
    long long d = x - 1;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (x == a)
            return true;
        if (check_composite(x, a, d, r))
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a;
    cin >> a;

    vector<long long> divisors;
    for (long long i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            divisors.push_back(i);
            if (i * i < a) {
                divisors.push_back(a / i);
            }
        }
    }

    sort(divisors.begin(), divisors.end());
    map<long long, vector<long long>> update;

    for (auto d : divisors) {
        if (d <= 2) {
            continue;
        }

        for (int i = 1; i <= 40; ++i) {
            long long l = 2, r = d;
            while (l < r) {
                long long m = (l + r) / 2;
                if (pow(m, i) < d - 1) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }

            if (pow(l, i) == d - 1 && miller_rabin(l)) {
                update[l].push_back(d);
                break;
            }
        }
    }

    map<long long, long long> ways = {{1, 1}};
    for (auto &[p, v] : update) {
        map<long long, long long> new_ways = ways;
        for (auto [a, b] : ways) {
            for (auto c : v) {
                if (binary_search(divisors.begin(), divisors.end(), a * c)) {
                    new_ways[a * c] += b;
                }
            }
        }
        ways = new_ways;
    }

    cout << ways[a] << "\n";
}