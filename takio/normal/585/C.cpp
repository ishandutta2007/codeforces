#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

void solve (LL x, LL y, int c) {
//    cout << x << ' ' << y <<' ' << c << endl;
    if (y == 0) return;
    if (x > y) {
        cout << (x - 1) / y << (char)('A' + c);
    }
    solve (y, x % y, c ^ 1);
}

int main () {
    LL x, y;
    cin >> x >> y;
    if (__gcd (x, y) > 1) { cout << "Impossible"; return 0; }
    solve (x, y, 0);
}