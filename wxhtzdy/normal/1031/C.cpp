#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int a, b;
    cin >> a >> b;

    int j = 0;
    for (int i = 0; i <= 1e5; i++) {
        if (i * (long long) (i + 1) / 2 <= a + b) {
            j = i;
        } else break;
    }

    vector<int> x, y;
    map<int, int> was;
    for (int i = j; i >= 1; i--) {
        if (a >= i) was[i] = 1, x.push_back(i), a -= i;
    }

    for (int i = j; i >= 1; i--) {
        if (b >= i && !was[i]) y.push_back(i), b -= i;
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    cout << x.size() << '\n';
    for (int i : x) cout << i << " ";
    cout << '\n';
    cout << y.size() << '\n';
    for (int i : y) cout << i << " ";
}