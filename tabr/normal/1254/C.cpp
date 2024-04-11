#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int b = 2;
    for (int i = 3; i <= n; i++) {
        cout << "2 1 " << b << " " << i << endl;
        int c;
        cin >> c;
        if (c == -1) {
            b = i;
        }
    }
    deque<int> deq;
    deq.emplace_back(1);
    deq.emplace_back(b);
    vector<ll> sz(n, 9e18);
    for (int i = 2; i <= n; i++) {
        if (i == b) {
            continue;
        }
        cout << "1 1 " << b << " " << i << endl;
        cin >> sz[i - 1];
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) { return sz[i] < sz[j]; });
    for (int i = 0; i < n - 3; i++) {
        int j = order[i] + 1, k = order[i + 1] + 1;
        cout << "2 1 " << j << " " << k << endl;
        int c;
        cin >> c;
        if (c == 1) {
            deq.emplace_back(j);
        } else {
            deq.emplace_front(j);
        }
    }
    deq.emplace_back(order[n - 3] + 1);
    while (deq.front() != 1) {
        deq.emplace_back(deq.front());
        deq.pop_front();
    }
    cout << 0 << " ";
    for (int i = 0; i < n; i++) {
        cout << deq.front() << " ";
        deq.pop_front();
    }
    cout << endl;
    return 0;
}