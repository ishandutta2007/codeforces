#include <bits/stdc++.h>
using namespace std;

const int ITERATIONS = 16;

mt19937 rng(42);

int r(int a, int b) {
    return uniform_int_distribution<int>(a, b)(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long answer = 0;
    for (int z = 0; z < ITERATIONS; ++z) {
        long long x = a[r(0, n - 1)];

        map<long long, int, greater<long long>> count;
        for (int i = 0; i < n; ++i) {
            ++count[gcd(x, a[i])];
        }

        long long temp = x;
        vector<long long> factors;
        for (long long p = 2; p * p <= temp; ++p) {
            if (temp % p == 0) {
                factors.push_back(p);
                while (temp % p == 0) temp /= p;
            }
        }
        if (temp > 1) factors.push_back(temp);

        for (auto p : factors) {
            for (auto [g, c] : count) {
                if (g % p == 0) count[g / p] += c;
            }
        }

        for (auto [g, c] : count) {
            if (c * 2 >= n) answer = max(answer, g);
        }
    }

    cout << answer << "\n";
}