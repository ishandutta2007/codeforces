#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

const int N = 2e5+7;

vector<int> g[N];
int l[N], r[N], ans;

ll dfs(int v) {
    ll f = 0;
    for (int to : g[v]) {
        f  += dfs(to);
    }

    f = min<ll>(f, r[v]);
    if (f < l[v]) f = r[v], ans++;
    return f;
}

void solve() {
    int n; cin >> n;

    ans = 0;

    for (int i = n; i--; ) g[i].clear();
    for (int i = 1; i < n; ++i) {
        int p; cin >> p;
        g[p-1].push_back(i);
    }

    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];

    dfs(0);

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}