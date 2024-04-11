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

constexpr int N = 1e7;
int vis[N + 1];

bool chmin(auto& x, auto y) { return y < x ? (x = y, true) : false; }

int main()
{ _
    fill(all(vis), -1);

    int n; cin >> n;

    ll ans = LINF;
    int iopt = -1, jopt = -1;

    for (int i = 0; i < n; ++i)
    {
        ll x; cin >> x;

        if (vis[x] != -1)
        {
            if (chmin(ans, x))
            {
                iopt = vis[x];
                jopt = i;
            }
            continue;
        }
        else vis[x] = i;
    }

    for (ll x = 1; x <= N; ++x)
    {
        ll first = LINF, second = LINF;
        int i = -1, j = -1;

        for (ll k = 1; x * k <= N; ++k) if (vis[x * k] != -1)
        {
            if (chmin(second, x * k))
            {
                j = vis[x * k];

                if (second < first)
                {
                    swap(second, first);
                    swap(i, j);
                }
            }
        }

        if (second < LINF && chmin(ans, first * second / x))
            tie(iopt, jopt) = minmax(i, j);
    }

    cout << iopt + 1 << " " << jopt + 1 << endl;

    exit(0);
}