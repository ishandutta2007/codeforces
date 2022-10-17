#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1, inv2 = (mod + 1) >> 1;

ll fact[MN], inv[MN];
ll choose(int N, int K){ return fact[N] * inv[K] % mod * inv[N - K] % mod; }
ll fpow(ll b, ll e){
    ll ret = 1;
    while (e){
        if (1 & e) ret = ret * b % mod;
        b = b * b % mod; e >>= 1;
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    fact[0] = inv[0] = 1;
    for (int i = 1; i < MN; ++i){
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = fpow(fact[i], mod - 2);
    }
    int T; cin >> T;
    while (T--){
        int N, M; ll K; cin >> N >> M >> K;
        if (N == M){
            cout << (K * N) % mod << '\n';
            continue;
        }
        M = N - M;
        ll ans = 0;
        for (int i = 1; i <= N; ++i){
            if (M - 1 > N - i - 1) continue;
            ans = (ans + i * K % mod * choose(N - i - 1, M - 1) % mod * fpow(inv2, N - i) % mod) % mod;
        }
        cout << ans << '\n';
    }  
}