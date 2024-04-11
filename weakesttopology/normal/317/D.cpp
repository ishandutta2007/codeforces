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

const int logmax = 30;
const int bad[] = {17, 19, 23, 29};

int solve(int mask) {
    static unordered_map<int, int> g;
    if (mask == 0) return 0;
    if (g.count(mask)) return g[mask];

    bool vis[logmax + 1]{};
    for (int i = 1; i < logmax && mask >> i; ++i) {
        if (not (mask >> i & 1)) continue;
        int nmask = mask;
        if (count(all(bad), i)) {
            bool stop = false;
            for (auto p : bad) {
                if ((mask >> p & 1) && p > i) stop = true;
            }
            if (stop) continue;
        }
        for (int j = i; j < logmax; j += i) {
            nmask &= ~(1 << j);
        }
        vis[solve(nmask)] = true;
    }
    int mex = 0;
    while (vis[mex]) ++mex;
    return g[mask] = mex;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int N = min(100000, n);
    auto [lp, pr] = sieve(N);

    int large = n - N + 1;

    int grundy = 0;
    for (int x = 2; x <= N; ++x) {
        int g = 0;
        for (int y = x, p = lp[y]; y > 1; p = lp[y]) {
            int e = 0;
            while (y % p == 0) ++e, y /= p;
            g = gcd(e, g);
        }
        if (g > 1) continue;

        int cnt = 0;
        ll y = x;
        while (y <= N) y *= x, ++cnt;
        large += cnt;
        while (y <= n) y *= x, ++cnt;
        large -= cnt;

        grundy ^= solve(((1 << cnt) - 1) << 1);
    }

    grundy ^= large & 1;

    cout << (grundy ? "Vasya" : "Petya") << endl;

    exit(0);
}