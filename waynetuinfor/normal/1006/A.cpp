#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) {
        if (v[i] % 2 == 0) cout << v[i] - 1 << ' ';
        else cout << v[i] << ' ';
    }
    cout << endl;
}