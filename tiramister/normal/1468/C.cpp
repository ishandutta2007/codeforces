#line 2 "/Users/tiramister/CompetitiveProgramming/Cpp/CppLibrary/Tools/heap_alias.hpp"

#include <queue>

template <class T>
using MaxHeap = std::priority_queue<T>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "main.cpp"
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    vector<bool> served;
    int id = 0, sid = 0;

    MaxHeap<pair<int, int>> heap;

    auto serve = [&](int i) {
        cout << i + 1 << " ";
        served[i] = true;
    };

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;

        switch (t) {
            case 1: {
                int m;
                cin >> m;

                served.push_back(false);
                heap.emplace(m, -(id++));
                break;
            }
            case 2: {
                while (served[sid]) ++sid;
                serve(sid);
                break;
            }
            case 3: {
                while (true) {
                    auto [m, i] = heap.top();
                    i = -i;
                    heap.pop();

                    if (!served[i]) {
                        serve(i);
                        break;
                    }
                }
                break;
            }
        }
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}