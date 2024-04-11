#include <bits/stdc++.h>
using namespace std;

const int N = 100001, L = __lg(N) + 1;

vector<int> factors[N];
bool primes[N];
int nxt[L][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;

        for (int j = 2; j * j <= a; ++j) {
            if (a % j == 0) {
                factors[i].push_back(j);
                while (a % j == 0) {
                    a /= j;
                }
            }
        }

        if (a > 1) {
            factors[i].push_back(a);
        }
    }

    for (int i = 1, j = 1; i <= n; ++i) {
        while (j <= n) {
            bool ok = true;
            for (auto k : factors[j]) {
                ok &= !primes[k];
            }

            if (!ok) {
                break;
            }

            for (auto k : factors[j]) {
                primes[k] = true;
            }
            ++j;
        }

        nxt[0][i] = j;

        for (auto k : factors[i]) {
            primes[k] = false;
        }
    }

    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= __lg(n); ++j) {
            nxt[j][i] = nxt[j - 1][i] == n + 1 ? n + 1 : nxt[j - 1][nxt[j - 1][i]];
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int ans = 0;
        for (int i = __lg(n); i >= 0; --i) {
            if (nxt[i][l] <= r) {
                l = nxt[i][l];
                ans += 1 << i;
            }
        }
        ++ans;

        cout << ans << "\n";
    }
}