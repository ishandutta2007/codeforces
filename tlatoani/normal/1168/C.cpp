//
// Created by Danny Mittal on 7/24/19.
//

#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

const int N_MAX = 300000;
const int MOD = 29;

int main() {
    int n, q;
    cin >> n >> q;
    int array[N_MAX + 1];
    for (int i = 1; i <= n; i++) {
        cin >> array[i];
    }
    tuple<int, int, int> queries[N_MAX + 1];
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        queries[i] = make_tuple(x, y, i);
    }
    sort(queries + 1, queries + q + 1);
    int dp[MOD][MOD];
    for (int from = 0; from < MOD; from++) {
        for (int to = 0; to < MOD; to++) {
            dp[from][to] = n + 1;
        }
    }
    int j = q;
    bool answer[N_MAX + 1];
    for (int i = n; i > 0; i--) {
        for (int to = 1; to <= N_MAX; to <<= 1) {
            if (to & array[i]) {
                for (int f = array[i]; f; f -= f & -f) {
                    dp[(f & -f) % MOD][to % MOD] = i;
                }
                for (int from = 1; from <= N_MAX; from <<= 1) {
                    if (from & array[i]) {
                        dp[from % MOD][to % MOD] = i;
                    }
                }
            } else {
                int least = n + 1;
                for (int f = array[i]; f; f -= f & -f) {
                    least = min(least, dp[(f & -f) % MOD][to % MOD]);
                }
                for (int f = array[i]; f; f -= f & -f) {
                    dp[(f & -f) % MOD][to % MOD] = least;
                }
            }
        }
        for (; q && get<0>(queries[j]) == i; j--) {
            int ax = array[get<0>(queries[j])];
            int ay = array[get<1>(queries[j])];
            answer[get<2>(queries[j])] = dp[(ax & -ax) % MOD][(ay & -ay) % MOD] <= get<1>(queries[j]);
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << (answer[i] ? "Shi\n" : "Fou\n");
    }
}