#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    long long t = 1;
    while (k--) t *= (long long)10;
    long long g = __gcd(t, (long long)n);
    cout << t * n / g << endl;
    return 0;
}