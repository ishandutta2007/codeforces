#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, t; cin >> n >> k >> t;
    if (t < k) cout << t << endl;
    else if (t < n) cout << k << endl;
    else if (t - n < k) cout << k - (t - n) << endl;
    else cout << k << endl;
    return 0;
}