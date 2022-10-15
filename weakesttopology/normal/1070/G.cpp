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
    int n, m; cin >> n >> m;

    vector s(m, 0), h(m, 0);

    for (int j = 0; j < m; ++j)
    {
        cin >> s[j] >> h[j]; --s[j];
    }

    vector init(n, 0);

    for (int i = 0; i < n; ++i) cin >> init[i];

    vector a(n, 0), vis(m, 0);

    auto checkhero = [&](int j, int pos)
    {
        int hp = h[j], d = pos > s[j] ? 1 : -1;
        for (int i = s[j]; true; i += d)
        {
            hp += a[i];
            if (hp < 0) return false;
            if (i == pos) break;
        }
        return true;
    };

    auto find = [&](int pos)
    {
        for (int j = 0; j < m; ++j)
            if (not vis[j] && checkhero(j, pos)) return j;
        return -1;
    };

    vector ans(0, 0);

    auto checkpos = [&](int pos)
    {
        ans.clear();

        for (int i = 0; i < n; ++i) a[i] = init[i];

        fill(all(vis), 0);

        for (int j = 0; j < m; ++j)
        {
            int z = find(pos);

            if (z == -1) return false;

            {
                int l = s[z], r = pos;

                if (l > r) swap(l, r);

                fill(begin(a) + l, begin(a) + r + 1, 0);
            }

            vis[z] = 1;

            ans.push_back(z);
        }

        return true;
    };

    int pos = 0;

    while (pos < n && not checkpos(pos)) ++pos;

    if (pos == n)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << pos + 1 << endl;

        for (auto j : ans) cout << j + 1 << " ";

        cout << endl;
    }

    exit(0);
}