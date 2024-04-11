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

const int amax = 1e4;

int main()
{ _
    int n, k; cin >> n >> k;

    map<int, vector<int>> H;

    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x; H[x].push_back(i);
    }

    vector op(0, pair(0, 0));

    for (int t = 0; t < k && size(H) > 1; ++t)
    {
        auto& [xmin, idxmin] = *begin(H);
        auto& [xmax, idxmax] = *rbegin(H);

        int i = idxmin.back(), j = idxmax.back();

        op.emplace_back(j, i);

        idxmin.pop_back(), idxmax.pop_back();

        H[xmin + 1].push_back(i), H[xmax - 1].push_back(j);

        if (empty(idxmin)) H.erase(begin(H));
        if (empty(idxmax)) H.erase(prev(end(H)));
    }

    int s = rbegin(H)->first - begin(H)->first;

    debug(s);

    cout << s << " " << size(op) << endl;

    for (auto [i, j] : op) cout << i + 1 << " " << j + 1 << endl;

    exit(0);
}