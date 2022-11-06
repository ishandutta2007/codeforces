#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a = 1, b = 2, c = 3;
    while (n--) {
        int t; cin >> t;
        if (t == c) return cout << "NO" << endl, 0;
        if (t == a) swap(b, c);
        else swap(a, c);
    }
    cout << "YES" << endl;
}