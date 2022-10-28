#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;

unsigned long long single_hash[N], factorial_hash[N];
int sieve[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    for (int i = 2; i <= n; ++i) {
        if (sieve[i] > 0) continue;
        for (int j = i; j <= n; j += i) sieve[j] = i;
    }

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 2; i <= n; ++i) {
        single_hash[i] = sieve[i] == i ? rng() : single_hash[i / sieve[i]] ^ single_hash[sieve[i]];
    }

    unsigned long long all_hash = 0;
    for (int i = 1; i <= n; ++i) {
        factorial_hash[i] = single_hash[i] ^ factorial_hash[i - 1];
        all_hash ^= factorial_hash[i];
    }

    if (all_hash == 0) {
        cout << n << "\n";
        for (int i = 1; i <= n; ++i) cout << i << " ";
        cout << "\n";
        exit(0);
    }

    for (int i = 1; i <= n; ++i) {
        if (factorial_hash[i] == all_hash) {
            cout << n - 1 << "\n";
            for (int j = 1; j <= n; ++j) if (j != i) cout << j << " ";
            cout << "\n";
            exit(0);
        }
    }

    map<unsigned long long, int> hash_map;
    for (int i = 1; i <= n; ++i) {
        if (hash_map.contains(all_hash ^ factorial_hash[i])) {
            int j = hash_map[all_hash ^ factorial_hash[i]];
            cout << n - 2 << "\n";
            for (int k = 1; k <= n; ++k) if (k != i && k != j) cout << k << " ";
            cout << "\n";
            exit(0);
        }
        hash_map[factorial_hash[i]] = i;
    }

    assert(n % 4 == 3);
    cout << n - 3 << "\n";
    for (int i = 1; i <= n - 1; ++i) if (i != 2 && i != n / 2) cout << i << " ";
    cout << "\n";
}