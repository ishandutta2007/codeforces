#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> order(n);
    iota(order.begin(), order.end(), 1);
    shuffle(order.begin(), order.end(), rng);
    int a = order[0], b = order[1];
    cout << "? " << a << " " << b << endl;
    int x;
    cin >> x;
    for (int k = 2; k < n; k++) {
        int i = order[k];
        cout << "? " << a << " " << i << endl;
        int y;
        cin >> y;
        if ((x & y) == y && x != y) {
            b = i;
            x = y;
            continue;
        }
        if (x != y) {
            continue;
        }
        cout << "? " << b << " " << i << endl;
        cin >> y;
        if ((x & y) == y && x != y) {
            a = i;
            x = y;
            continue;
        }
    }
    vector<int> ans(n);
    bool ok = false;
    for (int k = 0; k < n; k++) {
        int i = order[k];
        if (i == b || i == a) {
            continue;
        }
        cout << "? " << b << " " << i << endl;
        cin >> ans[i - 1];
        if (!ok) {
            cout << "? " << a << " " << i << endl;
            int y;
            cin >> y;
            if (ans[i - 1] < y) {
                ok = true;
            } else if (ans[i - 1] > y) {
                ok = true;
                ans[i - 1] = y;
                swap(a, b);
            }
        }
    }
    ans[a - 1] = x;
    cout << "! ";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}