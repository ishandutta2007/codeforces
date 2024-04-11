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
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    vector<int> p300(n);
    vector<int> pinv(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; i++) {
        int x = i;
        for (int j = 0; j < 300; j++) {
            x = p[x];
        }
        p300[i] = x;
    }
    for (int i = 0; i < n; i++) {
        pinv[p[i]] = i;
    }
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            x--, y--;
            swap(pinv[p[x]], pinv[p[y]]);
            swap(p[x], p[y]);
            for (int z : {x, y}) {
                vector<int> front(301);
                vector<int> back(301);
                front[0] = z;
                back[0] = z;
                for (int i = 1; i < 301; i++) {
                    front[i] = p[front[i - 1]];
                    back[i] = pinv[back[i - 1]];
                }
                for (int i = 0; i < 301; i++) {
                    p300[back[i]] = front[300 - i];
                }
            }
        } else {
            x--;
            while (y >= 300) {
                y -= 300;
                x = p300[x];
            }
            while (y >= 1) {
                y -= 1;
                x = p[x];
            }
            cout << x + 1 << '\n';
        }
    }
    return 0;
}