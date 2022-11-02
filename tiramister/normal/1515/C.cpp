#include <iostream>
#include <queue>

template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

using namespace std;
using lint = long long;

void solve() {
    int n, m;
    lint x;
    cin >> n >> m >> x;

    MinHeap<pair<lint, int>> heap;
    for (int i = 0; i < m; ++i) heap.emplace(0, i);

    cout << "YES\n";

    while (n--) {
        auto [d, i] = heap.top();
        heap.pop();
        cout << i + 1 << " ";

        lint h;
        cin >> h;
        heap.emplace(d + h, i);
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}