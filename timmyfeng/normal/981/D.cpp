#include <bits/stdc++.h>
using namespace std;

const int N = 60;

long long book[N];
bool ok[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> book[i];
    }

    long long mask = 0;
    for (int b = N - 1; b >= 0; --b) {
        mask ^= 1LL << b;

        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= n; ++j) {
                ok[i][j] = false;
            }
        }
        ok[0][0] = true;

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                long long sum = 0;
                for (int l = j; l < n; ++l) {
                    sum += book[l];
                    ok[i + 1][l + 1] |= ok[i][j] && (sum & mask) == mask;
                }
            }
        }

        if (!ok[k][n]) {
            mask ^= 1LL << b;
        }
    }

    cout << mask << "\n";
}