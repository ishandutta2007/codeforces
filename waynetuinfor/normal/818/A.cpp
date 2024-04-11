#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k; cin >> n >> k;
    long long t = n / (2 * (k + 1));
    cout << t << ' ' << t * k << ' ' << n - (k + 1) * t << endl;
    return 0;
}