#include <iostream>
#include <vector>

using namespace std;

const int INF = 1 << 30;

template <class T>
vector<T> Vec(size_t l, T v) { return vector<T>(l, v); }

template <class T, class... Ts>
auto Vec(size_t l, Ts... ts) {
    return vector<decltype(Vec<T>(ts...))>(l, Vec<T>(ts...));
}

int main() {
    int N;
    cin >> N;

    auto dp = Vec<int>(N + 1, 8, INF);
    dp[0][0] = 0;

    for (int i = 1; i <= N; ++i) {
        int c;
        string S;
        cin >> c >> S;
        int mask = 0;
        for (char c : S) {
            mask |= (1 << (c - 'A'));
        }

        for (int b = 0; b < 8; ++b) {
            dp[i][b] = min(dp[i][b], dp[i - 1][b]);  // unused
            dp[i][b | mask] = min(dp[i][b | mask], dp[i - 1][b] + c);
        }
    }
    cout << (dp[N][7] == INF ? -1 : dp[N][7]) << endl;
    return 0;
}