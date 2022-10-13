#include <iostream>
#include <vector>

using namespace std;

long long MOD = 1e9 + 7;
vector<long long> f, invf;
vector<long long> tpow;
const int MX = 4e5;
 
long long inv(long long b, long long p = MOD - 2) {
    if (p == 0) return 1LL;
    long long x = inv(b, p / 2);
    x = x * x % MOD;
    if (p % 2) x = x * b % MOD;
    return x;
}

long long ch(int n, long long k) {
    if (k > n || k < 0) return 0LL;
    return f[n] * invf[k] % MOD * invf[n - k] % MOD;
}

int main() {
    int n; long long T;
    cin >> n >> T;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    f.resize(MX + 1), invf.resize(MX + 1), tpow.resize(MX + 1);
    f[0] = 1LL;
    tpow[0] = 1LL;
    long long den = inv(2);
    for (int i = 1; i <= MX; i++) {
        tpow[i] = tpow[i - 1] * den % MOD;
    }
    for (int i = 1; i <= MX; i++)
        f[i] = f[i - 1] * i % MOD;
    invf.back() = inv(f.back());
    for (int i = MX - 1; i >= 0; i--)
        invf[i] = invf[i + 1] * (i + 1) % MOD;
    long long st = 1LL;
    long long ans = 0;
    long long left = T;
    for (int i = 0; i < n; i++) {
        left -= t[i];
        if (left < 0) break;
        else {
            left += t[i];
            // before: i C 0 + i C 1 + ... + i C left
            // after: (i + 1) C 0 + ... + (i + 1) C left - ((i + 1) C left + ... + (i + 1) C (left - t[i] + 1))
            long long nxt = st * 2 - ch(i, left) % MOD;
            for (int j = min(left, (long long) i + 1); j > left - t[i]; j--) {
                nxt -= ch(i + 1, j), nxt %= MOD;
            }
            left -= t[i];
            nxt %= MOD;
            ans += nxt * tpow[i + 1] % MOD;
            st = nxt;
            ans %= MOD;
        }
    }
    if (ans < 0) ans += MOD;
    cout << ans << "\n";
}