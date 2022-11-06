#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k; cin >> n >> k;
    long long d = 1;
    while (d <= n) d <<= 1;
    long long g = d - 1;
    d >>= 1;
    if (k == 1) cout << n << endl;
    else cout << g << endl;
}