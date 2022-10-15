#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n), o(n);
    o[0] = 1;
    for (int u = 1; u < n; ++u) {
        int p;
        cin >> p;
        --p;
        h[u] = h[p] + 1;
        o[h[u]] ^= 1;
    }
    cout << accumulate(begin(o), end(o), 0) << '\n';
    exit(0);
}