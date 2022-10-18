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
    vector<int> p(n);
    for (int i = 2; i <= n; i++) {
        cout << "? ";
        for (int j = 0; j < n - 1; j++) {
            cout << 1 << " ";
        }
        cout << i << endl;
        int k;
        cin >> k;
        k--;
        if (k != -1) {
            p[k] = i - 1;
        }
    }
    for (int i = 1; i < n; i++) {
        cout << "? ";
        for (int j = 0; j < n - 1; j++) {
            cout << n << " ";
        }
        cout << i << endl;
        int k;
        cin >> k;
        k--;
        if (k != -1) {
            p[k] = i - n;
        }
    }
    int c = *min_element(p.begin(), p.end());
    cout << "! ";
    for (int i : p) {
        cout << i - c + 1 << " ";
    }
    cout << endl;
    return 0;
}