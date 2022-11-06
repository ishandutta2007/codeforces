#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, mod = 1e9 + 7;
bool v[maxn];
vector<int> prime;

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) prime.emplace_back(i);
        for (int j = 0; i * prime[j] < maxn; ++j) {
            v[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

long long fpow(long long a, long long n) {
    long long ret = 1ll;
    for (; n; n >>= 1) {
        if (n & 1) ret *= a;
        a *= a;
    }
    return ret;
}

long long phi(long long n) {
    long long ret = 1ll;
    for (int p : prime) if (n % p == 0) {
        int k = 0;
        while (n % p == 0) n /= p, ++k;
        ret *= fpow(p, k - 1) * (long long)(p - 1);
    }
    if (n > 1) ret *= (n - 1);
    return ret;
}

int main() {
    sieve();
    long long n, k; cin >> n >> k;
    k = (k + 1) / 2;
    while (k && n > 1) {
        n = phi(n); --k;
    }
    cout << n % mod << endl;
    return 0;
}