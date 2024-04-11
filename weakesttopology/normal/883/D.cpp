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
    int n; cin >> n;

    string s; cin >> s;

    vector packmen(0, 0), prefix(n, 0);

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '*') prefix[i] = 1;

        if (s[i] == 'P') packmen.push_back(i);

        if (i > 0) prefix[i] += prefix[i - 1];
    }

    auto query = [&](int l, int r)
    {
        r = min(r, n - 1);
        if (r < l || r < 0) return 0;
        else if (l <= 0) return prefix[r];
        else return prefix[r] - prefix[l - 1];
    };

    int m = size(packmen);

    vector dp(m + 1, 0);

    auto check = [&](int limit)
    {
        fill(all(dp), 0);

        for (int j = 0; j < m; ++j)
        {
            int impossible = query(dp[j], packmen[j] - limit - 1);

            if (impossible > 0) return false;

            int left = query(dp[j], packmen[j] - 1);

            if (left == 0) dp[j + 1] = packmen[j] + limit + 1;

            else
            {
                dp[j + 1] = packmen[j] + 1;

                if (j > 0 && query(dp[j - 1], packmen[j] - limit - 1) == 0)
                    dp[j + 1] = max(dp[j + 1], packmen[j - 1] + limit + 1);
            }
        }

        return query(dp[m], n - 1) == 0;

    };

    debug(size(packmen));

    if (size(packmen) == 1)
    {
        int suml = 0, costl = 0;

        for (int i = packmen[0]; i >= 0; i -= 1)
            if (s[i] == '*') suml += 1, costl = abs(i - packmen[0]);

        int sumr = 0, costr = 0;

        for (int i = packmen[0]; i < n; i += 1)
            if (s[i] == '*') sumr += 1, costr = abs(i - packmen[0]);

        int sum = max(suml, sumr), cost = INF;

        if (suml == sum) cost = min(cost, costl);
        if (sumr == sum) cost = min(cost, costr);

        cout << sum << " " << cost << endl;
    }
    else
    {
        int cost = -1;

        for (int z = n; z > 0; z >>= 1)
            while (not check(cost + z)) cost += z;

        cost += 1;

        int sum = query(0, n - 1);

        cout << sum << " " << cost << endl;
    }

    exit(0);
}