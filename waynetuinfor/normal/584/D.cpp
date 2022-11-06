#include <bits/stdc++.h>
#define __int128 long long
using namespace std;

// n < 4759123141     chk = [2, 7, 61]
// n < 1122004669633  chk = [2, 13, 23, 1662803]
// n < 2^64           chk = [2, 325, 9375, 28178, 450775, 9780504, 1795265022]

const int maxn = 32000 + 10;
vector<int> chk = { 2, 7, 61 };
vector<int> prime;
bool v[maxn];

long long fpow(long long a, long long n, long long mod) {
    long long ret = 1LL;
    for (; n; n >>= 1) {
        if (n & 1) ret = (__int128)ret * (__int128)a % mod;
        a = (__int128)a * (__int128)a % mod;
    }
    return ret;
}
bool check(long long a, long long u, long long n, int t) {
    a = fpow(a, u, n);
    if (a == 0) return true;
    if (a == 1 || a == n - 1) return true;
    for (int i = 0; i < t; ++i) {
        a = (__int128)a * (__int128)a % n;
        if (a == 1) return false;
        if (a == n - 1) return true;
    }
    return false;
}
bool is_prime(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    long long u = n - 1; int t = 0;
    for (; u & 1; u >>= 1, ++t);
    for (long long i : chk) {
        if (!check(i, u, n, t)) return false;
    }
    return true;
}

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) prime.push_back(i);
        for (int j = 0; i * prime[j] < maxn; ++j) {
            v[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }    
}

int main() {
    sieve();
    int n; cin >> n;
    if (is_prime(n)) {
        cout << 1 << '\n' << n << endl;
        return 0;
    }
    for (int i : prime) {
        if (is_prime(n - i)) {
            cout << 2 << '\n' << i << ' ' << n - i << endl;
            return 0;
        }
    }
    for (int i = 0; i < prime.size(); ++i) {
        for (int j = i; j < prime.size(); ++j) {
            if (n >= prime[i] + prime[j] && is_prime(n - prime[i] - prime[j])) {
                cout << 3 << '\n' << prime[i] << ' ' << prime[j] << ' ' << n - prime[i] - prime[j] << endl;
                return 0;
            }
        }
    }
    return 0;
}