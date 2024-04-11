#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e9;
const int N = 4e5 + 5;
mt19937 rng(time(0));

struct Frac {
    LL up, down;
    Frac(const LL &a, const LL &b) {
        up = a, down = b;
        this->reduce();
    }
    Frac operator+(const Frac &y) const {
        LL up1 = up * y.down + down * y.up, down1 = down * y.down;
        return Frac(up1, down1);
    }
    Frac operator-(const Frac &y) const {
        LL up1 = up * y.down - down * y.up, down1 = down * y.down;
        return Frac(up1, down1);
    }
    Frac operator*(const Frac &y) const {
        LL up1 = up * y.up, down1 = down * y.down;
        return Frac(up1, down1);
    }
    Frac operator/(const Frac &y) const {
        LL up1 = up * y.down, down1 = down * y.up;
        return Frac(up1, down1);
    }
    bool operator<(const Frac &y) const {
        return (*this - y).up < 0;
    }
    bool operator==(const Frac &y) const {
        return this->up == y.up && this->down == y.down;
    }

    void reduce() {
        LL g = __gcd(up, down);
        up /= g, down /= g;
        if (down < 0)
            up = -up, down = -down;
    }
};
namespace std {
template <>
class hash<Frac> {
  public:
    size_t operator()(const Frac &x) const {
        long long s = abs(x.up) + abs(x.down);
        return s * s + x.up;
    }
};
}; // namespace std

int n;
int vis[N];
vector<ar2> g[N], ans;

int dfs(int x) {
    vis[x] = 1;
    int no_match = 0;
    for (auto ele : g[x]) {
        int u = ele[0], id = ele[1], to_match = 0;
        if (!vis[u])
            to_match = dfs(u);
        if (to_match) {
            ans.PB({id, to_match});
        } else if (vis[u] == 2) {
            if (no_match)
                ans.PB({no_match, id}), no_match = 0;
            else
                no_match = id;
        }
    }
    vis[x] = 2;
    return no_match;
}

int main() {
    scanf("%d", &n);
    unordered_map<Frac, int> slope_id;

    int num = 0;
    rep(i, 1, n) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        Frac x(a, b), y(c, d);
        Frac k1 = y / (x + Frac(1, 1)), k2 = (y + Frac(1, 1)) / x;

        int u, v;
        u = !slope_id.count(k1) ? (slope_id[k1] = ++num) : slope_id[k1];
        v = !slope_id.count(k2) ? (slope_id[k2] = ++num) : slope_id[k2];
        g[u].PB({v, i}), g[v].PB({u, i});
    }

    memset(vis, 0, sizeof vis);
    rep(i, 1, num) if (!vis[i]) dfs(i);
    printf("%d\n", ans.size());
    for (auto ele : ans)
        printf("%d %d\n", ele[0], ele[1]);
    return 0;
}