#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

auto sieve(int N) {
    vector<int> lp(N + 1, 0), pr;
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) pr.push_back(lp[i] = i);
        for (auto p : pr) {
            if (p > lp[i] || i * p > N) break;
            lp[i * p] = p;
        }
    }
    return pair(lp, pr);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    constexpr int amax = 1e5;
    auto [lp, pr] = sieve(amax);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    vector<int> last(amax + 1, n), nxt(n);

    for (int i = n - 1, r = n; i >= 0; --i) {
        for (int x = a[i]; x != 1; x /= lp[x]) r = min(r, last[lp[x]]);
        for (int x = a[i]; x != 1; x /= lp[x]) last[lp[x]] = i;
        nxt[i] = r;
    }

    constexpr int K = 18;
    vector<array<int, K>> go(n + 1);
    fill(all(go[n]), n);

    for (int i = 0; i < n; ++i) go[i][0] = nxt[i];
    for (int x = 1; x < K; ++x) {
        for (int i = 0; i < n; ++i) {
            go[i][x] = go[go[i][x - 1]][x - 1];
        }
    }

    for (int z = 0; z < q; ++z) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int cost = 0;
        for (int x = K - 1; x >= 0; --x) {
            if (go[l][x] <= r) {
                cost += 1 << x;
                l = go[l][x];
            }
        }
        cost += 1;
        cout << cost << endl;
    }

    exit(0);
}