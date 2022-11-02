#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <limits>

using lint = long long;

template <class T>
using MaxHeap = std::priority_queue<T>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        int n;
        std::cin >> n;

        std::vector<std::pair<int, lint>> mps(n);
        for (auto& mp : mps) {
            std::cin >> mp.first >> mp.second;
        }
        std::sort(mps.rbegin(), mps.rend());

        lint ans = 0;
        int rem = 0;
        MinHeap<lint> heap;
        for (auto mp : mps) {
            heap.push(mp.second);
            ++rem;
            if (rem + mp.first > n) {
                ans += heap.top();
                heap.pop();
                --rem;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}