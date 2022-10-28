#include <bits/stdc++.h>
using namespace std;

const int K = 21, N = 200001;

int prob[K][N], order[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int m, k;
        cin >> m >> k;
        for (int j = 1; j < K; ++j) {
            prob[j][m] += min(j, k);
        }
    }

    iota(order + 1, order + N, 1);

    int optimal_t = 1;
    long long optimal_sum = 0;
    for (int t = 1; t < K; ++t) {
        sort(order + 1, order + N, [&](int a, int b) {
            return prob[t][a] > prob[t][b];
        });

        long long sum = 0;
        for (int i = 1; i <= t; ++i) {
            sum += prob[t][order[i]];
        }

        if (sum * optimal_t > optimal_sum * t) {
            optimal_t = t, optimal_sum = sum;
        }
    }

    long long sum = 0;
    for (int t = 1; t < N; ++t) {
        sum += prob[K - 1][t];
        if (t >= K && sum * optimal_t > optimal_sum * t) {
            optimal_t = t, optimal_sum = sum;
        }
    }

    sort(order + 1, order + N, [&](int a, int b) {
        return prob[min(K - 1, optimal_t)][a] > prob[min(K - 1, optimal_t)][b];
    });

    cout << optimal_t << "\n";
    for (int i = 1; i <= optimal_t; ++i) {
        cout << order[i] << " ";
    }
    cout << "\n";
}