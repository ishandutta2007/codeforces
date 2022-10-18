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
    auto ask = [&](int i) {
        cout << "? " << i << endl;
        int k;
        cin >> k;
        if (k == 1) {
            cout << "! " << i << endl;
            exit(0);
        }
        return k;
    };
    int p = 1;
    int t = ask(1);
    for (int i = 20; i >= 0; i--) {
        int nxt = p;
        if (p - (1 << i) >= 1) {
            int s = ask(p - (1 << i));
            if (s < t) {
                t = s;
                nxt = p - (1 << i);
            }
        }
        if (p + (1 << i) <= n) {
            int s = ask(p + (1 << i));
            if (s < t) {
                t = s;
                nxt = p + (1 << i);
            }
        }
        p = nxt;
    }
    cout << "! " << p << endl;
    return 0;
}