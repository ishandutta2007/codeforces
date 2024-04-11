#include <bits/stdc++.h>
using namespace std;
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
    vector<int> p(n, n);
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    for (int i = 0; i < n - 1; i++) {
        int x = o[0];
        int y = o[1];
        cout << "? " << x + 1 << " " << y + 1 << endl;
        int a;
        cin >> a;
        cout << "? " << y + 1 << " " << x + 1 << endl;
        int b;
        cin >> b;
        if (a > b) {
            p[x] = a;
            o.erase(o.begin());
        } else {
            p[y] = b;
            o.erase(o.begin() + 1);
        }
    }
    cout << "! ";
    for (int i : p) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}