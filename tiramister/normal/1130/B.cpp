#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using ll = long long;

template <class T>
vector<T> Vec(size_t l, T v) { return vector<T>(l, v); }

template <class T, class... Ts>
auto Vec(size_t l, Ts... ts) {
    return vector<decltype(Vec<T>(ts...))>(l, Vec<T>(ts...));
}

int main() {
    int N;
    cin >> N;

    auto p = Vec<int>(2, N + 1, -1);
    p[0][0] = p[1][0] = 0;
    for (int i = 0; i < N * 2; ++i) {
        int a;
        cin >> a;
        if (p[0][a] < 0) {
            p[0][a] = i;
        } else {
            p[1][a] = i;
        }
    }

    ll ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < N; ++j) {
            ans += abs(p[i][j + 1] - p[i][j]);
        }
    }

    cout << ans << endl;
    return 0;
}