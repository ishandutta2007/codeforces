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
    int w, h, n; cin >> w >> h >> n;

    multiset<pair<int, int>> V, H;

    int N = 3 * n, idx = 2;

    vector vis(N, 0), len(N, 0);

    priority_queue<pair<int, int>> pqV, pqH;

    V.emplace(h, 0), H.emplace(w, 1);

    pqV.emplace(h, 0), pqH.emplace(w, 1);

    len[0] = h, len[1] = w;

    for (int i = 0; i < n; ++i)
    {
        char c; cin >> c;

        auto& T = (c == 'H' ? V : H);
        auto& pq = (c == 'H' ? pqV : pqH);

        int y; cin >> y;

        auto iter = T.lower_bound(pair(y, 0));

        auto [r, id] = *iter;

        int l = r - len[id];

        if (l < y && y < r)
        {
            T.emplace(y, idx), T.emplace(r, idx + 1);

            T.erase(iter);

            vis[id] = 1;

            pq.emplace(y - l, idx), pq.emplace(r - y, idx + 1);

            len[idx] = y - l, len[idx + 1] = r - y;

            idx += 2;
        }

        while (vis[pqV.top().second]) pqV.pop();
        while (vis[pqH.top().second]) pqH.pop();

        ll ans = 1LL * pqV.top().first * pqH.top().first;

        cout << ans << endl;
    }

    exit(0);
}