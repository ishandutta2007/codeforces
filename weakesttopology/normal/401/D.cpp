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

int main()
{ _
    string s; cin >> s;
    int m; cin >> m;

    int N = size(s);

    vector dp((1 << N) * m, 0LL);

    auto get = [&](int mask, int rem) -> ll&
    {
        return dp[mask * m + rem];
    };

    get(0, 0) = 1;

    for (int mask = 0; mask < (1 << N); ++mask)
    {
        for (int i = 0; i < N; ++i) if ((mask >> i & 1) == 0 && (mask || (s[i] != '0')))
            for (int x = 0; x < m; ++x)
            {
                {
                    int rem = (10 * x + (s[i] - '0')) % m;
                    get(mask | (1 << i), rem) += get(mask, x);
                }
            }
    }

    ll ans = get((1 << N) - 1, 0);

    for (int d = '0'; d <= '9'; ++d)
    {
        int k = 0;
        for (auto c : s) k += c == d;

        for (int x = 1; x <= k; ++x) ans /= x;
    }

    cout << ans << endl;

    exit(0);
}