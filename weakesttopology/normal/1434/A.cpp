#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    constexpr int K = 6;

    array<int, K> a;

    for (int j = 0; j < K; ++j) cin >> a[j];

    int n; cin >> n;

    vector b(n, 0);

    for (int i = 0; i < n; ++i) cin >> b[i];

    vector m(0, pair(0, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < K; ++j)
            m.emplace_back(b[i] - a[j], i);

    sort(all(m));

    vector pos(n, array<int, K>());
    vector nxt(n, 0);

    for (int idx = 0; idx < size(m); ++idx)
    {
        int i = m[idx].second;
        pos[i][nxt[i]++] = idx;
    }

    multiset<int> S;

    for (int i = 0; i < n; ++i)
    {
        sort(all(pos[i]));
        S.insert(m[pos[i][0]].first);
    }

    nxt.assign(n, 0);

    int ans = *rbegin(S) - *begin(S);

    for (int idx = 0; idx < size(m); ++idx)
    {
        auto [fret, i] = m[idx];

        S.erase(S.find(fret));

        if (++nxt[i] < K)
        {
            int nxtfret = m[pos[i][nxt[i]]].first;

            S.insert(nxtfret);

            ans = min(ans, *rbegin(S) - *begin(S));
        }
        else
            break;
    }

    cout << ans << endl;

    exit(0);
}