#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    long long mn = n - l + 1, pw = 1;
    for (int i = 0; i < l - 1; i++) pw *= 2, mn += pw;
    cout << mn << " ";
    pw = 1;
    long long mx = 1;
    for (int i = 0; i < r - 1; i++) pw *= 2, mx += pw;
    mx += (n - r) * pw;
    cout << mx;
    return 0;
}