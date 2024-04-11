#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

using T = ll;

inline bool equal(const T& a, const T& b) { return abs(a - b) == 0LL; }

struct point
{
    T x, y;
    point() : x(0), y(0) {}
    point(T x, T y) : x(x), y(y) {}
    point& operator+=(const point &rhs) { x += rhs.x, y += rhs.y; return *this; }
    point& operator-=(const point &rhs) { x -= rhs.x, y -= rhs.y; return *this; }
    point& operator*=(const T& rhs) { x *= rhs, y *= rhs; return *this; }
    point& operator/=(const T& rhs) { x /= rhs, y /= rhs; return *this; }
    point operator+(const point &rhs) const { return point(*this) += rhs; }
    point operator-(const point &rhs) const { return point(*this) -= rhs; }
    point operator*(const T& rhs) const { return point(*this) *= rhs; }
    point operator/(const T& rhs) const { return point(*this) /= rhs; }
    bool operator==(const point& rhs) const { return equal(x, rhs.x) && equal(y, rhs.y); }
    bool operator<(const point& rhs) const { return pair(x, y) < pair(rhs.x, rhs.y); }
};

T det(const point& p, const point& q) { return p.x * q.y - p.y * q.x; }

bool cw(const point& p, const point& q, const point& r)
{
    return det(q - p, r - q) <= 0;
}

class LCA
{
private:
    const vector<vector<int>>& E;
    const int n, lg;
    vector<int> L, R, h;
    vector<vector<int>> up;
    void dfs(int u, int p)
    {
        h[u] = h[p] + 1, up[u][0] = p;
        for (int i = 1; i < lg; ++i)
            up[u][i] = up[up[u][i-1]][i-1];
        static int ct = 0;
        L[u] = ct;
        for (int v : E[u])
            if (v != p) dfs(v, u);
        R[u] = ct++;
    }
public:
    LCA(const vector<vector<int>>& E, int root) : E(E), n(sz(E)), lg(32 - __builtin_clz(n))
    {
        L.assign(n, 0), R.assign(n, 0), h.assign(n, -1);
        up.assign(n, vector<int>(lg));
        dfs(root, root);
    }
    bool is_ancestor(int u, int v) const
    {
        return L[u] <= L[v] && R[v] <= R[u];
    }
    int lca(int u, int v) const
    {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = lg - 1; i >= 0; --i)
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        return up[u][0];
    }
    int distance(int u, int v) const
    {
        int w = lca(u, v);
        return h[u] + h[v] - 2 * h[w];
    }
};

int main()
{ _
    int n; cin >> n;
    vector<point> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].y;

    vector E(n, vector(0, 0));

    vector st(1, n - 1);
    for (int i = n - 2; i >= 0; --i)
    {
        while (sz(st) > 1 && not cw(p[i], p[st[sz(st) - 1]], p[st[sz(st) - 2]]))
            st.pop_back();
        E[st.back()].push_back(i);
        st.push_back(i);
    }

    LCA lca(E, n - 1);

    int m; cin >> m;

    while (m--)
    {
        int u, v; cin >> u >> v; --u, --v;
        int ans = lca.lca(u, v) + 1;
        cout << ans << endl;
    }

    exit(0);
}