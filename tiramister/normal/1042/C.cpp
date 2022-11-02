#include <iostream>
#include <vector>

using namespace std;

template <class T>
vector<T> Vec(size_t l, T v) { return vector<T>(l, v); }

template <class T, class... Ts>
auto Vec(size_t l, Ts... ts) {
    return vector<decltype(Vec<T>(ts...))>(l, Vec<T>(ts...));
}

const int INF = 1 << 30;

void merge(int i, int j) {
    cout << 1 << ' ' << i << ' ' << j << '\n';
}

void erase(int i) {
    cout << 2 << ' ' << i << '\n';
}

int main() {
    int N;
    cin >> N;
    auto a = Vec<int>(N + 1, -INF);
    for (int i = 1; i <= N; ++i) cin >> a[i];

    int micnt = 0, miidx = 0;
    for (int i = 1; i <= N; ++i) {
        if (a[i] < 0) {
            ++micnt;
            if (a[miidx] < a[i]) miidx = i;
        }
    }
    if (micnt & 1) a[miidx] = 0;

    vector<int> used, unused;
    for (int i = 1; i <= N; ++i) {
        if (a[i] == 0) {
            unused.push_back(i);
        } else {
            used.push_back(i);
        }
    }

    if (!unused.empty()) {
        while (unused.size() > 1) {
            merge(unused.back(), unused.front());
            unused.pop_back();
        }
    }

    if (!used.empty()) {
        if (!unused.empty()) erase(unused.front());
        while (used.size() > 1) {
            merge(used.back(), used.front());
            used.pop_back();
        }
    }
    return 0;
}