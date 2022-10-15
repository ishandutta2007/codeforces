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
    ll n, m, k; cin >> n >> m >> k;

    map<ll, int> memo;

    function<int(ll)> solve = [&](ll x)
    {
        if (memo.count(x)) return memo[x];

        vector<int> nxt;

        for (ll d = 1; d * d <= x; ++d) if (x % d == 0)
        {
            vector<pair<ll, ll>> ch = { { d, x / d }, { x / d, x } };
            for (auto [y, ct] : ch)
            {
                if (y < k || y == x) continue;
                if (ct % 2) nxt.push_back(solve(y));
                else nxt.push_back(0);
            }
        }

        sort(all(nxt)), nxt.erase(unique(all(nxt)), end(nxt));

        int mex = 0;
        while (mex < size(nxt) && nxt[mex] == mex) ++mex;

        return memo[x] = mex;
    };

    int grundy = n % 2 ? solve(m) : 0;

    string ans = grundy ? "Timur" : "Marsel";

    cout << ans << endl;

    exit(0);
}