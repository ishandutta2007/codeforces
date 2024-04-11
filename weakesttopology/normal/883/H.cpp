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

    map<char, int> ct;

    for (int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        ct[c] += 1;
    }

    int oddct = 0;

    for (auto [c, k] : ct) if (k % 2) oddct += 1;

    vector div(0, 0);

    for (int x = 1; x <= n; ++x)
        if (n % x == 0) div.push_back(x);

    auto check = [&](int x) // check if size x is possible
    {
        int y = n / x;

        if (x % 2 && y < oddct) return false;

        if (x % 2 == 0 && oddct > 0) return false;

        return true;
    };

    int ans = -1;

    for (auto x : div) if (check(n / x))
    {
        ans = x;
        break;
    }

    cout << ans << endl;

    vector<string> pld(ans);

    vector<string> center(ans);

    int idx = 0;

    if ((n / ans) % 2)
    {
        for (auto& [c, k] : ct)
        {
            if (ct[c] % 2)
            {
                center[idx++].push_back(c);
                ct[c]--;
            }
        }

        for (auto& [c, k] : ct)
        {
            while (idx < ans && ct[c] > 0)
            {
                center[idx++].push_back(c);
                center[idx++].push_back(c);
                ct[c] -= 2;
            }
        }

        idx = 0;
    }

    for (auto& [c, k] : ct)
    {
        while (idx < ans && ct[c] > 0)
        {
            int sz = 2 * size(pld[idx]) + size(center[idx]);

            int z = min(ct[c], n / ans - sz);

            pld[idx] += string(z / 2, c);

            ct[c] -= z;

            if (sz + z == n / ans) ++idx;
        }
    }

    for (int i = 0; i < ans; ++i)
    {
        cout << pld[i] << center[i];
        reverse(all(pld[i]));
        cout << pld[i];
        cout << " ";
    }

    exit(0);
}