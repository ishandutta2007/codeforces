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

void fail()
{
    cout << 0 << endl;
    exit(0);
}

int main()
{ _
    int n, m, d; cin >> n >> m >> d;

    vector affected(n, 0);

    for (int j = 0; j < m; ++j)
    {
        int v; cin >> v; --v;
        affected[v] = 1;
    }

    vector E(n, vector(0, 0));

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b; cin >> a >> b; --a, --b;
        E[a].push_back(b), E[b].push_back(a);
    }

    vector H(n, vector(0, 0));

    function<int(int, int, int)> getheights = [&](int u, int p, int h)
    {
        int hmax = affected[u] ? h : -1;

        vector<int> hs;
        for (auto v : E[u])
        {
            if (v != p)
            {
                int hcur = getheights(v, u, h + 1);
                if (hcur != -1)
                {
                    H[u].push_back(hcur - h);
                    hmax = max(hmax, hcur);
                }
                else H[u].push_back(-1);
            }
            else H[u].push_back(-1);
        }

        return hmax;
    };

    getheights(0, 0, 0);

    vector mex(n, vector(0, 0));

    vector maxdist(n, -1);

    for (int u = 0; u < n; ++u)
    {
        int deg = size(E[u]);

        mex[u].assign(deg, -1);

        for (int i = 1, mx = H[u][i - 1]; i < deg; ++i)
        {
            mex[u][i] = max(mex[u][i], mx);
            mx = max(mx, H[u][i]);
        }
        for (int  i = deg - 2, mx = H[u][i + 1]; i >= 0; --i)
        {
            mex[u][i] = max(mex[u][i], mx);
            mx = max(mx, H[u][i]);
        }

        for (int i = 0; i < deg; ++i)
            maxdist[u] = max(maxdist[u], H[u][i]);
    }


    function<void(int, int, int)> compute = [&](int u, int p, int up)
    {
        if (affected[u]) up = max(up, 0);

        maxdist[u] = max(maxdist[u], up);

        int deg = size(E[u]);

        for (int i = 0; i < deg; ++i) if (int v = E[u][i]; v != p)
        {
            int nxt = max(mex[u][i], up);
            compute(v, u, nxt == -1 ? -1 : nxt + 1);
        }
    };

    compute(0, 0, -1);

    int ans = 0;

    for (int u = 0; u < n; ++u) if (maxdist[u] <= d) ans += 1;

    cout << ans << endl;

    exit(0);
}