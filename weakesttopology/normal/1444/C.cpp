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
    int n, m, k; cin >> n >> m >> k;

    vector c(n, 0);

    for (int i = 0; i < n; ++i) { cin >> c[i]; --c[i]; }

    vector E(n, vector(0, 0));

    for (int j = 0; j < m; ++j)
    {
        int a, b; cin >> a >> b; --a, --b;
        E[a].push_back(b), E[b].push_back(a);
    }

    vector bip(k, 1), color(n, -1), p(n, -1);

    vector rt(k, vector(0, 0));

    function<bool(int)> paint = [&](int u)
    {
        for (auto v : E[u]) if (c[v] == c[u])
        {
            if (color[v] == -1)
            {
                color[v] = color[u] ^ 1;
                p[v] = p[u];
                if (not paint(v)) return false;
            }
            else if (color[v] == color[u])
                return false;
        }
        return true;
    };

    for (int u = 0; u < n; ++u) if (color[u] == -1)
    {
        color[u] = 0, p[u] = u;
        rt[c[u]].push_back(u);
        bip[c[u]] = bip[c[u]] && paint(u);
    }

    vector matches(0, tuple(0, 0, 0, 0, 0));

    vector vis(n, 0);

    function<void(int)> match = [&](int u)
    {
        vis[u] = 1;
        for (auto v : E[u])
        {
            if (c[v] == c[u] && not vis[v]) match(v);
            else if (c[v] < c[u] && bip[c[v]])
                matches.emplace_back(c[v], color[v], p[v], color[u], p[u]);
        }
    };

    ll ans = 0LL;

    int N = 2 * n;

    vector F(N, vector(0, 0));

    auto id = [&n](int u, int c) { return c * n + u; };

    for (int u = 0; u < n; ++u)
        F[id(u, 0)].push_back(id(u, 1)), F[id(u, 1)].push_back(id(u, 0));

    vector colorcheck(N, -1);

    stack<int> save, roots;

    function<bool(int)> check = [&](int u)
    {
       save.push(u);
        for (auto v : F[u])
        {
            if (colorcheck[v] == -1)
            {
                colorcheck[v] = colorcheck[u] ^ 1;
                if (not check(v)) return false;
            }
            else if (colorcheck[v] == colorcheck[u])
                return false;
        }
        return true;
    };

    auto reset = [&](int u)
    {
        colorcheck[u] = -1;
        F[u].clear();
        F[u].push_back(u < n ? n + u : u - n);
    };

    for (int j = 0, ctbip = 0; j < k; ctbip += bip[j++])
    {
        if (not bip[j]) continue;

        if (empty(rt[j])) { ans += ctbip; continue; }

        matches.clear();

        for (auto u : rt[j]) match(u);

        sort(all(matches)), matches.erase(unique(all(matches)), end(matches));

        int cut = !!size(matches);

        for (int i = 1; i < size(matches); ++i)
            cut += get<0>(matches[i]) != get<0>(matches[i - 1]);

        ans += ctbip - cut;

        matches.emplace_back(-1, 0, 0, 0, 0);

        int last = get<0>(matches[0]);

        for (auto [cv, colorv, pv, coloru, pu] : matches)
        {
            if (cv != last)
            {
                bool bipcheck = true;

                while (not empty(roots))
                {
                    int u = roots.top(); roots.pop();
                    if (colorcheck[u] == -1)
                    {
                        colorcheck[u] = 0;
                        bipcheck = bipcheck && check(u);
                    }
                }

                cut -= not bipcheck;

                while (not empty(save)) { int u = save.top(); save.pop(); reset(u); }
            }

            last = cv;

            if (cv == -1) break;

            int vcpy = id(pv, colorv), ucpy = id(pu, coloru);

            F[vcpy].push_back(ucpy), F[ucpy].push_back(vcpy);

            save.push(vcpy), save.push(ucpy), roots.push(vcpy);
        }

        ans += cut;
    }

    cout << ans << endl;

    exit(0);
}