#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    if (n == 4) {
        cout << "-1" << endl;
        return 0;
    }
    int a, b, c, d; cin >> a >> b >> c >> d;
    if (k < n + 1) return cout << "-1" << endl, 0;
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        if (i != a && i != b && i != c  && i != d) v.push_back(i);
    }
    cout << a << ' ' << c << ' ';
    for (int i = 0; i < v.size(); ++i) cout << v[i] << ' '; cout << d << ' ' << b << endl;
    cout << c << ' ' << a << ' ';
    for (int i = 0; i < v.size(); ++i) cout << v[i] << ' '; cout << b << ' ' << d << endl;
    return 0;
}