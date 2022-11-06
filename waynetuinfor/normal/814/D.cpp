#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const long double pi = acos(-1);

struct C {
    int x, y, r;
    bool operator<(const C& rhs) const {
        return r < rhs.r;
    }
} c[maxn];

vector<int> T[maxn];
bool rt[maxn], v[maxn];
long double ans = 0.0;

bool overlap(int, int);
void dfs(int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> c[i].x >> c[i].y >> c[i].r;
    sort(c, c + n);
    memset(rt, true, sizeof(rt));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) if (overlap(i, j)) {
            T[j].push_back(i);
            rt[i] = false;
            break;
        }
    }
    for (int i = 0; i < n; ++i) if (rt[i]) {
        if (!v[i]) dfs(i, -1, 0), ans += (long double)c[i].r * (long double)c[i].r * pi;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}

bool overlap(int i, int j) {
    if (c[i].r > c[j].r) return false;
    return (long long)(c[i].x - c[j].x) * (long long)(c[i].x - c[j].x) + (long long)(c[i].y - c[j].y) * (long long)(c[i].y - c[j].y) <= (long long)(c[i].r - c[j].r) * (long long)(c[i].r - c[j].r);
}

void dfs(int x, int fa, int dep) {
    v[x] = true;
    for (int u : T[x]) if (u != fa) {
        dfs(u, x, dep + 1);
    }
    if (dep & 1 && dep) ans += (long double)c[x].r * (long double)c[x].r * pi;
    else if (dep) ans -= (long double)c[x].r * (long double)c[x].r * pi;
}