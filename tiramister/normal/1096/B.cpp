#include <iostream>
#include <string>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

int main() {
    int N;
    string S;
    cin >> N >> S;

    ll l, r;
    for (l = 1; l < N; ++l) {
        if (S[l] != S[0]) break;
    }
    for (r = 1; r < N; ++r) {
        if (S[N - r - 1] != S[N - 1]) break;
    }

    ll ans = l + r + 1;
    if (S[0] == S[N - 1]) ans += l * r;

    cout << ans % MOD << endl;
    return 0;
}