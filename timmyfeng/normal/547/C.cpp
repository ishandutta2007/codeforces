#include <bits/stdc++.h>
using namespace std;

const int N = 500000 + 1;

vector<int> products[N];
int multiples[N], a[N];
long long ans;

void solve(vector<array<int, 3>> queries, int l, int r) {
    vector<int> stk;
    for (auto [a, b, x] : queries) {
        if (a <= l && r <= b) {
            for (int i = 0; i < (int) products[x].size(); ++i) {
                int y = products[x][i];
                if (__builtin_parity(i) == 0) {
                    ans += multiples[y];
                } else {
                    ans -= multiples[y];
                }
                ++multiples[y];
            }
            stk.push_back(x);
        }
    }

    if (l == r) {
        cout << ans << "\n";
    } else {
        vector<array<int, 3>> left, right;
        int m = (l + r) / 2;

        for (auto [a, b, x] : queries) {
            if (a <= l && r <= b) {
                continue;
            }

            if (a <= m) {
                left.push_back({a, b, x});
            }
            if (b > m) {
                right.push_back({a, b, x});
            }
        }

        solve(left, l, m);
        solve(right, m + 1, r);
    }

    while (!stk.empty()) {
        int x = stk.back();
        stk.pop_back();
        for (int i = 0; i < (int) products[x].size(); ++i) {
            int y = products[x][i];
            --multiples[y];
            if (__builtin_parity(i) == 0) {
                ans -= multiples[y];
            } else {
                ans += multiples[y];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < N; ++i) {
        int x = i;
        vector<int> factors;
        for (int j = 2; j * j <= x; ++j) {
            if (x % j == 0) {
                while (x % j == 0) {
                    x /= j;
                }
                factors.push_back(j);
            }
        }
        if (x > 1) {
            factors.push_back(x);
        }

        products[i].resize(1 << factors.size());
        for (int j = 0; j < (1 << factors.size()); ++j) {
            if (j == 0) {
                products[i][j] = 1;
            } else {
                products[i][j] = products[i][j & (j - 1)] *
                    factors[__builtin_ctz(j)];
            }
        }
    }

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<array<int, 3>> queries;
    map<int, int> prv;

    for (int i = 1; i <= q; ++i) {
        int x;
        cin >> x;
        if (prv.count(x) == 0) {
            prv[x] = i;
        } else {
            queries.push_back({prv[x], i - 1, a[x]});
            prv.erase(x);
        }
    }

    for (auto [x, p] : prv) {
        queries.push_back({p, q, a[x]});
    }

    solve(queries, 1, q);
}