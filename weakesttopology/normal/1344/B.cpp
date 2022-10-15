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

void fail(string s)
{
    debug(s);
    cout << -1 << endl;
    exit(0);
}

auto tarjan(const auto& E)
{
    int n = size(E);
    vector low(n, -1), num(n, -1), scc(n, -1), active(n, 0);
    stack<int> st; int ct = 0;
    function<void(int)> dfs = [&](int u)
    {
        low[u] = num[u] = ct++;
        active[u] = 1; st.push(u);
        for (auto v : E[u])
        {
            if (num[v] == -1) dfs(v);
            if (active[v]) low[u] = min(low[u], low[v]);
        }
        if (low[u] == num[u]) do
        {
            scc[st.top()] = u;
            active[st.top()] = 0; st.pop();
        } while (not st.empty() && num[st.top()] >= num[u]);
    };
    for (int u = 0; u < n; ++u) if (num[u] == -1) dfs(u);
    return scc;
}

int main()
{ _
    int n, m; cin >> n >> m;

    vector a(n, vector(m, 0));

    bool empty = true;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            char c; cin >> c;
            if (c == '#') a[i][j] = 1, empty = false;
        }

    if (empty)
    {
        cout << 0 << endl;
        exit(0);
    }

    bool badrow = false, badcol = false;

    for (int i = 0; i < n; ++i)
    {
        auto values = a[i];

        if ((int)distance(begin(values), unique(all(values))) > 2 + !values[0])
            fail("failed row");

        int ct = 0;
        for (int j = 0; j < m; ++j) ct += a[i][j];
        if (ct == 0) badrow = true;
    }

    for (int j = 0; j < m; ++j)
    {
        vector values(0, 0);

        for (int i = 0; i < n; ++i) values.push_back(a[i][j]);

        if ((int)distance(begin(values), unique(all(values))) > 2 + !values[0])
            fail("failed col");

        int ct = 0;
        for (int i = 0; i < n; ++i) ct += a[i][j];
        if (ct == 0) badcol = true;
    }

    if (badrow xor badcol) fail("badrow xor badcol");

    int N = n * m;

    vector E(N, vector(0, 0));

    auto id = [&](int i, int j) { return i * m + j; };

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0, jprv = 0; j < m; ++j) if (a[i][j])
        {
            while (not a[i][jprv]) ++jprv;
            while (jprv < j)
            {
                E[id(i, jprv)].push_back(id(i, jprv + 1));
                ++jprv;
            }
        }

        for (int j = m - 1, jprv = m - 1; j >= 0; --j) if (a[i][j])
        {
            while (not a[i][jprv]) --jprv;
            while (jprv > j)
            {
                E[id(i, jprv)].push_back(id(i, jprv - 1));
                --jprv;
            }
        }
    }

    for (int j = 0; j < m; ++j)
    {
        for (int i = 0, iprv = 0; i < n; ++i) if (a[i][j])
        {
            while (not a[iprv][j]) ++iprv;
            while (iprv < i)
            {
                E[id(iprv, j)].push_back(id(iprv + 1, j));
                ++iprv;
            }
        }

        for (int i = n - 1, iprv = n - 1; i >= 0; --i) if (a[i][j])
        {
            while (not a[iprv][j]) --iprv;
            while (iprv > i)
            {
                E[id(iprv, j)].push_back(id(iprv - 1, j));
                --iprv;
            }
        }
    }

    auto scc = tarjan(E);

    vector root(N, 1);

    for (int u = 0; u < N; ++u) if (a[u / m][u % m])
        for (auto v : E[u]) if (scc[u] != scc[v]) root[scc[v]] = 0;

    int ans = 0;

    for (int u = 0; u < N; ++u) if (a[u / m][u % m])
        ans += (scc[u] == u && root[u]);

    cout << ans << endl;

    exit(0);
}