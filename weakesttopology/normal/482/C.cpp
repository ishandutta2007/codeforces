
#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;
using ld = long double;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

constexpr int nmax = 50, smax = 20;

int weight[1 << smax];
ll ambiguity[1 << smax];

ld prob[1 << smax];

int main()
{ _
    int n; cin >> n;

    vector<string> s(n);
    for (auto& x : s) cin >> x;

    int m = size(s[0]);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) if (i != j)
        {
            int cap = 0;
            for (int k = 0; k < m; ++k)
            {
                if (s[i][k] == s[j][k]) cap |= 1 << k;
            }
            ambiguity[cap] |= (1LL << i) | (1LL << j);
        }

    for (int mask = (1 << m) - 1; mask >= 0; --mask)
    {
        for (int k = 0; k < m; ++k) if ((mask >> k & 1) == 0)
        {
            ambiguity[mask] |= ambiguity[mask | (1 << k)];
        }
    }

    prob[0] = 1;

    for (int mask = 1; mask < (1 << m); ++mask)
    {
        weight[mask] = 1 + weight[mask & (mask - 1)];
        for (int k = 0; k < m; ++k) if (mask >> k & 1)
            prob[mask] += prob[mask ^ (1 << k)] / (m - weight[mask] + 1);
    }

    ld ans = 0.0;

    for (int mask = 0; mask < (1 << m); ++mask)
    {
        int wamb = __builtin_popcountll(ambiguity[mask]);
        ans += wamb * prob[mask] / n;
    }

    cout << setprecision(20) << fixed;
    cout << ans << endl;

    exit(0);
}