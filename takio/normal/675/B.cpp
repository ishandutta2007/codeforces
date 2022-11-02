#include <cstdio>
#include <iostream>
#define LL long long
using namespace std;

const LL MOD = 1000000007;

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int mx = 0;
    mx = max (mx, a + b);
    mx = max (mx, a + c);
    mx = max (mx, d + b);
    mx = max (mx, c + d);
    int mn = 1e9;
    mn = min (mn, a + b);
    mn = min (mn, a + c);
    mn = min (mn, d + b);
    mn = min (mn, c + d);
    cout << max (0LL, 1LL * (n - mx + mn) * n) << endl;
}