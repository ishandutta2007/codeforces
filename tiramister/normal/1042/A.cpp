#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <class T>
vector<T> Vec(size_t l, T v) { return vector<T>(l, v); }

template <class T, class... Ts>
auto Vec(size_t l, Ts... ts) {
    return vector<decltype(Vec<T>(ts...))>(l, Vec<T>(ts...));
}

template <typename T>
inline T iceil(T n, T d) { return (n + d - 1) / d; }

int main() {
    int N, M;
    cin >> N >> M;
    auto a = Vec<int>(N, 0);
    for (int& v : a) cin >> v;

    sort(a.begin(), a.end());
    int ma = a.back() + M;

    for (int i = 0; i < N; ++i) {
        while (a[i] < a.back() && M > 0) {
            ++a[i];
            --M;
        }
    }
    int mi = a.back() + iceil(M, N);

    cout << mi << " " << ma << endl;
    return 0;
}