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

int main() {
    int N;
    cin >> N;

    auto a = Vec<int>(N, 0);
    for (int& v : a) cin >> v;
    sort(a.begin(), a.end());

    auto ans = Vec<int>(N, 0);
    int itr[2] = {0, N - 1};
    for (int i = 0; i < N; ++i) {
        ans[itr[i & 1]] = a[i];
        itr[i & 1] += (i & 1 ? -1 : 1);
    }

    for (int v : ans) cout << v << " ";
    cout << endl;
    return 0;
}