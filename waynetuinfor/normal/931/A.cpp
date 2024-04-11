#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    int t = (a + b) / 2;
    int ta = t - a, tb = b - t;
    cout << ta * 1ll * (ta + 1) / 2 + tb * 1ll * (tb + 1) / 2 << endl;
}