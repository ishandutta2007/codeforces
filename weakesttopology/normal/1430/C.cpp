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

void solve()
{
    int n; cin >> n;

    multiset<int> S[2];

    for (int i = 1; i <= n; ++i)
        S[i & 1].insert(i);

    vector op(0, pair(0, 0));

    while (max(size(S[0]), size(S[1])) >= 2)
    {
        int i = size(S[0]) < 2 ? 1 : size(S[1]) < 2 ? 0 : (*rbegin(S[0]) > *rbegin(S[1])) ? 0 : 1;

        auto iteru = prev(end(S[i])), iterv = prev(iteru);
        int u = *iteru, v = *iterv;
        S[i].erase(iteru);
        S[i].erase(iterv);
        int w = (u + v) / 2;
        S[w & 1].insert(w);
        op.emplace_back(u, v);
    }

    int best = -1;

    if (not S[0].empty() && not S[1].empty())
    {
        int u = *begin(S[0]), v = *begin(S[1]);
        op.emplace_back(u, v);
        best = (u + v + 1) / 2;
    }
    else if (not S[0].empty()) best = *begin(S[0]);
    else best = *begin(S[1]);

    cout << best << endl;
    for (auto [u, v] : op) cout << u << " " << v << endl;
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}