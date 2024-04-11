#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int a, int b) {  // [a, b]
    return uniform_int_distribution<int>(a, b)(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    /*
    vector<int> a(n, k);
    vector<int> b(n);
    auto move = [&]() {
        for (int i = 2; i < n - 1; i++) {
            b[i] = a[i + 1] / 2 + (a[i - 1] + 1) / 2;
        }
        b[0] = a[1] / 2 + (a[n - 1] + 1) / 2;
        b[1] = a[0] + a[2] / 2;
        b[n - 1] = (a[n - 2] + 1) / 2;
        swap(a, b);
    };
    for (int i = 0; i < 10; i++) {
        move();
        debug(a);
    }
    return 0;
    */
    int t;
    int p = get_rand(1, n);
    cout << "? 1" << endl;
    cin >> t;
    for (int i = 0; i < 600; i++) {
        cout << "? " << p << endl;
        cin >> t;
        if (k != t) {
            break;
        }
        p += i + 1;
        while (p > n) {
            p -= n;
        }
        assert(i != 599);
    }
    if (t > k) {
        while (true) {
            p--;
            if (p == 0) {
                p = n;
            }
            cout << "? " << p << endl;
            cin >> t;
            if (k == t) {
                break;
            }
        }
    } else {
        while (true) {
            p++;
            if (p == n + 1) {
                p = 1;
            }
            cout << "? " << p << endl;
            cin >> t;
            if (k == t) {
                break;
            }
        }
    }
    cout << "! " << p << endl;
    return 0;
}