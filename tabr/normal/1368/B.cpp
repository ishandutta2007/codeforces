#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k;
    cin >> k;
    string t = "codeforces";
    vector<ll> a(10, 1);
    ll mul = 1;
    while (mul < k) {
        sort(a.begin(), a.end());
        mul /= a[0];
        a[0]++;
        mul *= a[0];
    }
    for (int i = 0; i < 10; i++) {
        cout << string(a[i], t[i]);
    }
    cout << '\n';
    return 0;
}