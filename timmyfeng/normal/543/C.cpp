#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int A = 26;

int sum[1 << N], cost[N][N], n, m;
string strings[N];

void update(int mask, int cost) {
    for (int i = 0; i < (1 << n); ++i) {
        if (sum[i] < INT_MAX) {
            sum[i | mask] = min(sum[i | mask], sum[i] + cost);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> cost[i][j];
        }
    }

    fill(sum + 1, sum + (1 << n), INT_MAX);

    for (int i = 0; i < n; ++i) {
        update(1 << i, *min_element(cost[i], cost[i] + m));
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < A; ++j) {
            int mask = 0, sum = 0, maxi = 0;
            for (int k = 0; k < n; ++k) {
                if (strings[k][i] == j + 'a') {
                    mask |= 1 << k;
                    sum += cost[k][i];
                    maxi = max(maxi, cost[k][i]);
                }
            }

            if (mask > 0) {
                update(mask, sum - maxi);
            }
        }
    }

    cout << sum[(1 << n) - 1] << "\n";
}