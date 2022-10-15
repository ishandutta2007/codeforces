#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void fail()
{
    cout << -1 << endl;
}

void solve()
{
    int n; cin >> n;

    ll W; cin >> W;

    vector w(n, pair(0LL, 0));

    ll tot = 0LL;

    for (int i = 0; i < n; ++i)
    {
        cin >> w[i].first;
        w[i].second = i;

        tot += w[i].first;
    }

    sort(rall(w));

    if (w.back().first > W || tot < (W + 1) / 2) return fail();

    vector ans(0, 0);

    ll C = 0LL;

    for (auto [x, i] : w)
    {
        if ((W + 1) / 2 <= x && x <= W)
        {
            C = x;
            ans = vector(1, i);
            break;
        }
        else if (x < (W + 1) / 2)
        {
            C += x;
            ans.push_back(i);
            if (C >= (W + 1) / 2) break;
        }
    }

    if (C < (W + 1) / 2) return fail();

    sort(all(ans));

    cout << size(ans) << endl;
    for (auto i : ans) cout << i + 1 << " ";
    cout << endl;
}


int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}