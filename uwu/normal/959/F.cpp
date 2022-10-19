#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

int basis[MN][20], zeroes[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    zeroes[0] = 1;
    for (int i = 1; i <= N; ++i){
        int a; cin >> a;
        bool zero = 1;
        for (int j = 19; j >= 0; --j){
            basis[i][j] = basis[i - 1][j];
            if (!(1 & (a >> j))) continue;
            if (!basis[i][j]){
                basis[i][j] = a;
                a = 0;
                zero = 0;
            }
            else a ^= basis[i][j];
        }
        zeroes[i] = zeroes[i - 1];
        if (zero) zeroes[i] = zeroes[i] * 2 % mod;
    }
    while (Q--){
        int i, x; cin >> i >> x;
        for (int j = 19; j >= 0; --j){
            if (!basis[i][j]) continue;
            x = min(x, x ^ basis[i][j]);
        }
        cout << (x == 0) * (zeroes[i]) % mod << '\n';
    }
}