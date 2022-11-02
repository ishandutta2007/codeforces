#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <typename T>
T gcd(T a, T b) {
    if (a < b) return gcd(b, a);
    return b == 0 ? a : gcd(b, a % b);
}

const int MAX = 2e7;
bool isprime[MAX];
vector<int> primes;

void sieve() {
    fill(isprime, isprime + MAX, true);
    for (int p = 2; p * p < MAX; ++p) {
        if (!isprime[p]) continue;
        primes.push_back(p);
        for (int q = p; p * q < MAX; ++q) {
            isprime[p * q] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    sieve();

    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i) cin >> a[i];

    int g = 0;
    for (int i = 0; i < N; ++i) g = gcd(g, a[i]);
    for (int i = 0; i < N; ++i) a[i] /= g;

    map<int, int> cnt;
    for (int i = 0; i < N; ++i) {
        for (int p : primes) {
            if (p * p > a[i]) break;
            if (a[i] % p > 0) continue;
            if (!cnt.count(p)) cnt[p] = 0;
            ++cnt[p];
            while (a[i] % p == 0) a[i] /= p;
        }

        if (a[i] > 1) {
            if (!cnt.count(a[i])) cnt[a[i]] = 0;
            ++cnt[a[i]];
        }
    }

    int ans = N;
    for (auto p : cnt) {
        if (p.second < N) ans = min(ans, N - p.second);
    }
    cout << (ans == N ? -1 : ans) << endl;
    return 0;
}