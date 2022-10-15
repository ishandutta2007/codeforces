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

    enum border { enter = 0, leave = 1 };

    vector<int> l(n), r(n), t(n);

    vector<tuple<int, int, int>> sweep;

    for (int i = 0; i < n; ++i)
    {
        cin >> l[i] >> r[i] >> t[i]; --t[i];
        sweep.emplace_back(l[i], enter, i);
        sweep.emplace_back(r[i], leave, i);
    }

    sort(all(sweep));

    multiset<pair<int, int>> S[2];

    int ans = n;

    vector<int> vis(n, 0);

    for (auto [coord, state, i] : sweep)
    {
        int x = t[i], y = t[i] ^ 1;
        if (state == enter)
        {
            S[x].emplace(r[i], i);
        }
        else if (not vis[i])
        {
            auto iter = S[y].lower_bound(pair(l[i], -1));
            if (iter != end(S[y]))
            {
                int j = iter->second;
                vis[i] = vis[j] = 1, ans -= 1;
                S[y].erase(iter);
                S[x].erase(S[x].find(pair(r[i], i)));
            }
        }
    }

    cout << ans << endl;

    exit(0);
}