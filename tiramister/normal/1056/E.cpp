#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll mypow(ll b, ll n) {
    if (n == 0) return 1;
    if (n == 1) return b % MOD;
    return n % 2 == 0 ? mypow(b * b % MOD, n / 2) : mypow(b, n - 1) * b % MOD;
}

class RollingHash {
public:
    RollingHash(string S, ll _base = 26, ll _mod = 1e9 + 7) : base(_base), mod(_mod), len(S.length()) {
        hash.resize(len + 1);
        bpow.resize(len + 1);

        hash[0] = 0;
        bpow[0] = 1;
        for (int i = 0; i < len; ++i) {
            hash[i + 1] = (hash[i] * base + S[i]) % mod;
            bpow[i + 1] = bpow[i] * base % mod;
        }
    }

    ll seghash(int b, int e) {
        return (hash[e] - hash[b] * bpow[e - b] % mod + mod) % mod;
    }

    vector<ll> hash, bpow;
    ll base, mod;
    int len;
};


int main() {
    string S, T;
    cin >> S >> T;
    int N = S.length(), M = T.length();

    RollingHash rh(T);

    if (S[0] == '1') {
        for (int i = 0; i < N; ++i) {
            S[i] = '0' + '1' - S[i];
        }
    }

    int ob = -1, cnt[2] = {0, 0};
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1' && ob < 0) ob = i;
        ++cnt[S[i] - '0'];
    }

    int ans = 0;
    for (int z = 1; z < M; ++z) {
        if (cnt[0] * z >= M) break;
        if ((M - cnt[0] * z) % cnt[1] > 0) continue;
        int o = (M - cnt[0] * z) / cnt[1];

        ll zh = rh.seghash(0, z);
        ll oh = rh.seghash(z * ob, z * ob + o);

        if (zh == oh) continue;

        ll H = 0;
        for (char c : S) {
            if (c == '0') {
                H = (H * mypow(26LL, z) + zh) % MOD;
            } else {
                H = (H * mypow(26LL, o) + oh) % MOD;
            }
        }

        if (H == rh.seghash(0, M)) ++ans;
    }

    cout << ans << endl;
    return 0;
}