#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int dist[N];

void set_min(int &a, int b) { if (b < a) a = b; }
void set_max(int &a, int b) { if (b > a) a = b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(dist + 2, dist + N, INT_MAX);
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (i + i / j < N) set_min(dist[i + i / j], dist[i] + 1);
        }
    }

    int max_dist = *max_element(dist, dist + N);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> b(n);
        for (auto &i : b) cin >> i;

        vector<int> c(n);
        for (auto &i : c) cin >> i;

        k = min(k, max_dist * n);

        vector max_coins(n + 1, vector(k + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (j + dist[b[i]] <= k) {
                    set_max(max_coins[i + 1][j + dist[b[i]]], max_coins[i][j] + c[i]);
                }
                set_max(max_coins[i + 1][j], max_coins[i][j]);
            }
        }

        cout << *ranges::max_element(max_coins[n]) << "\n";
    }
}