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

ll solve()
{
    int n, k; cin >> n >> k;

    vector pos(n, 0);

    for (int i = 0; i < n; ++i)
    {
        int a; cin >> a; --a;
        pos[a] = i;
    }

    vector b(k, 0);

    for (int j = 0; j < k; --b[j++]) cin >> b[j];

    set<int> S;

    for (int i = 0; i < n; ++i) S.insert(i);

    vector rem(n, 1);

    for (auto x : b) rem[pos[x]] = 0;

    const ll mod = 998244353LL;

    ll ans = 1LL;

    for (auto x : b)
    {
        int i = pos[x];

        auto iter = S.find(i);

        bool prv = (iter != begin(S)) && rem[*prev(iter)];
        bool nxt = (next(iter) != end(S)) && rem[*next(iter)];

        if (not prv && not nxt) return 0LL;

        if (prv && nxt) ans = (2LL * ans) % mod;

        int j = prv ? *prev(iter) : *next(iter);

        rem[j] = 0, rem[i] = 1;

        S.erase(j);
    }

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}