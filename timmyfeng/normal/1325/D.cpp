#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long u, v;
    cin >> u >> v;

    if (u % 2 != v % 2 || u > v) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> freq(60);
    for (int i = 0; i < 60; ++i) {
        if (u & (1LL << i)) {
            ++freq[i];
        }
    }
    for (int i = 0; i < 60; ++i) {
        if ((u & (1LL << i)) != (v & (1LL << i))) {
            freq[i - 1] += 2;
            u += 1LL << i;
        }
    }

    vector<long long> a(*max_element(freq.begin(), freq.end()));
    for (int i = 0; i < 60; ++i) {
        for (int j = 0; j < freq[i]; ++j) {
            a[j] |= 1LL << i;
        }
    }
    cout << a.size() << '\n';
    for (auto i : a) {
        cout << i << ' ';
    }
    cout << '\n';
}