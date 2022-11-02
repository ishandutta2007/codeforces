#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using lint = long long;
constexpr lint INF = 1LL << 60;

lint add(lint a, lint b) {
    return std::min(a + b, INF);
}

lint mul(lint a, lint b) {
    return (a >= INF / b ? INF : std::min(a * b, INF));
}

constexpr int N = 50;
std::vector<lint> perm, cycnum, cnt;

void init() {
    perm.assign(N + 1, 1);
    for (int i = 1; i <= N; ++i) perm[i] = mul(perm[i - 1], i);

    // 
    cycnum.assign(N + 1, 1);
    for (int i = 2; i <= N; ++i) cycnum[i] = perm[i - 2];

    // 
    cnt.assign(N + 1, 0);
    cnt[0] = 1;
    for (int n = 1; n <= N; ++n) {
        for (int i = 1; i <= n; ++i) {
            cnt[n] = add(cnt[n], mul(cycnum[i], cnt[n - i]));
        }
    }
}

// nk
std::vector<int> sim(int n, lint k) {
    // union find
    std::vector<int> par(n);
    std::iota(par.begin(), par.end(), 0);

    std::vector<int> ret(n);
    par[n - 1] = 0;
    ret[0] = n - 1;

    for (int i = 1; i < n - 1; ++i) {
        int j = k / cycnum[n - i];
        k %= cycnum[n - i];

        // 
        int p = par[i];
        while (p != par[p]) p = par[p];

        // j
        int idx = -1;
        do {
            ++idx;
            while (idx == p || idx != par[idx]) ++idx;
        } while (j--);

        ret[i] = idx;
        par[idx] = i;
    }

    // n-1
    int p = par[n - 1];
    while (p != par[p]) p = par[p];
    ret[n - 1] = p;
    return ret;
}

void solve() {
    int n;
    lint k;
    std::cin >> n >> k;

    if (k > cnt[n]) {
        std::cout << -1 << std::endl;
        return;
    }

    --k;
    int x = 0;  // 

    while (x < n) {
        int m = n - x;
        for (int i = 1; i <= m; ++i) {
            if (k < mul(cycnum[i], cnt[m - i])) {
                // i
                for (auto a : sim(i, k / cnt[m - i])) {
                    std::cout << a + x + 1 << " ";
                }

                // 
                k %= cnt[m - i];
                x += i;
                break;
            } else {
                k -= mul(cycnum[i], cnt[m - i]);
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    init();

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}