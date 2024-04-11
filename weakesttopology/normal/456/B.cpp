#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int modpow(int x, int p, int mod)
{
    int res = 1;
    while (p > 0)
    {
        if (p & 1) res = res * x % mod;
        p >>= 1, x = x * x % mod;
    }
    return res;
}

int main()
{ _
    string s; cin >> s;

    constexpr int K = 4, mod = 5;

    array<int, K> pow; fill(all(pow), 1);

    for (auto c : s)
        for (int x = 0; x < K; ++x)
            pow[x] = modpow(pow[x], 10, mod) * modpow(x + 1, c - '0', mod) % mod;

    int ans = accumulate(all(pow), 0) % mod;

    cout << ans << endl;

    exit(0);
}