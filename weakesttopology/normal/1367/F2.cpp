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

int compress(auto& v)
{
    auto w = v;
    sort(all(w)), w.erase(unique(all(w)), end(w));
    for (auto& x : v)
    {
        auto iter = lower_bound(all(w), x);
        x = (int)distance(begin(w), iter);
    }
    return size(w);
}

int solve()
{
    int n; cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int m = compress(a);

    vector<vector<int>> pos(m);
    vector<int> L(m, INF), R(m, -INF), cnt(m, 0);

    for (int i = 0; i < n; ++i)
    {
        int x = a[i];
        L[x] = min(L[x], i);
        R[x] = max(R[x], i);
        pos[x].push_back(i);
        cnt[x] += 1;
    }

    for (int x = 1; x < m; ++x) cnt[x] += cnt[x - 1];

    auto query = [&](int l, int r) { return cnt[r] - (l ? cnt[l - 1] : 0); };

    int ans = INF;

    for (int l = 0, r = 0; l < m; ++l, r = max(r, l))
    {
        while (r + 1 < m && R[r] < L[r + 1]) ++r;
        int cur = query(l, r);
        if (l > 0)
        {
            auto iter = lower_bound(all(pos[l - 1]), L[l]);
            cur += (int)distance(begin(pos[l - 1]), iter);
        }
        if (r + 1 < m)
        {
            auto iter = upper_bound(all(pos[r + 1]), R[r]);
            cur += (int)distance(iter, end(pos[r + 1]));
        }
        ans = min(ans, n - cur);
    }

    for (int x = 0; x + 1 < m; ++x)
    {
        int ct = size(pos[x + 1]);
        vector<int> mixed;
        merge(all(pos[x]), all(pos[x + 1]), back_inserter(mixed));
        for (auto i : mixed)
        {
            ct += a[i] == x ? +1 : -1;
            ans = min(ans, n - ct);
        }
    }

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}