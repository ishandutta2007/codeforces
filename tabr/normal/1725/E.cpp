#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int MAX_A = 200010;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &x : A)
        cin >> x;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        U--, V--;
        G[U].emplace_back(V);
        G[V].emplace_back(U);
    }

    vector<int> min_factor(MAX_A);
    iota(min_factor.begin(), min_factor.end(), 0);
    for (int i = 2; i < MAX_A; i++) {
        if (min_factor[i] < i)
            continue;
        for (int j = i + i; j < MAX_A; j += i)
            min_factor[j] = i;
    }
    vector<vector<int>> primes(N);
    vector<int> sum(MAX_A, 0);
    for (int i = 0; i < N; i++) {
        while (A[i] > 1) {
            int p = min_factor[A[i]];
            while (A[i] % p == 0)
                A[i] /= p;
            primes[i].emplace_back(p);
            sum[p]++;
        }
    }

    ll ans = 0;
    vector<map<int, int>> cnt(N);
    auto comb = [](int x) { return 1LL * x * (x - 1) / 2 % MOD; };
    vector<ll> val(N, 0);

    auto dfs = [&](auto self, int v, int pp) -> void {
        for (int x : primes[v]) {
            cnt[v][x] += 1;
            val[v] += 1 * 1LL * comb(sum[x] - 1);
            val[v] %= MOD;
        }
        for (int &u : G[v]) {
            if (u == pp)
                continue;
            self(self, u, v);
            auto &cur = cnt[v];
            auto &nxt = cnt[u];
            if (cur.size() < nxt.size()) {
                swap(cur, nxt);
                swap(val[v], val[u]);
            }
            for (auto e : nxt) {
                int p = e.first, y = e.second;
                int x = cur[p];
                val[v] -=
                    x * 1LL * comb(sum[p] - x) + comb(x) * 1LL * (sum[p] - x);
                cur[p] += y;
                x += y;
                val[v] +=
                    x * 1LL * comb(sum[p] - x) + comb(x) * 1LL * (sum[p] - x);
                val[v] %= MOD;
                val[v] += MOD;
                val[v] %= MOD;
            }
        }
        ans += val[v];
    };
    dfs(dfs, 0, -1);
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
    cout << ans << "\n";
}