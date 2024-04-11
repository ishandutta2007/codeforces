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
    int n, k, m; cin >> n >> k >> m;

    vector x(k, 0);

    set<tuple<int, ll, int>> L, R;

    for (int z = 0; z < k; ++z)
    {
        cin >> x[z]; --x[z];
        L.emplace(x[z], 0, -z), R.emplace(x[z], 0, +z);
    }

    using LI = pair<ll, int>;
    priority_queue<LI, vector<LI>, greater<LI>> pq;

    for (int j = 0; j < m; ++j)
    {
        ll t; cin >> t;

        int a, b; cin >> a >> b; --a, --b;

        if (not empty(pq))
        {
            ll s = empty(L) ? max(t, pq.top().first) : t;
            while (not empty(pq) && pq.top().first <= s)
            {
                auto [v, z] = pq.top(); pq.pop();
                L.emplace(x[z], -v, -z), R.emplace(x[z], +v, +z);
            }
        }

        auto iterR = R.lower_bound(tuple(a, -1LL, -1));

        auto iterL = L.lower_bound(tuple(a, +1LL, +1));

        int ans = -1;

        ll avail = -1;

        if (iterR == end(R) || iterL == begin(L))
        {
            bool right = iterR == end(R);
            auto iter = (right ? prev(iterL) : iterR);
            ll dummy;
            tie(dummy, avail, ans) = *iter;
        }
        else
        {
            iterL = prev(iterL);
            auto [l, aa, u] = *iterL;
            auto [r, bb, v] = *iterR;
            ll dummy;
            if (tuple(a - l, -aa, -u) > tuple(r - a, +bb, +v))
                tie(dummy, avail, ans) = *iterR;
            else
                tie(dummy, avail, ans) = *iterL;
        }

        avail = abs(avail), ans = abs(ans);

        ll wait = max(0LL, avail - t) + abs(x[ans] - a);

        L.erase(tuple(x[ans], -avail, -ans)), R.erase(tuple(x[ans], +avail, +ans));

        x[ans] = b;

        pq.emplace(t + wait + abs(a - b), ans);

        cout << ans + 1 << " " << wait << endl;
    }

    exit(0);
}