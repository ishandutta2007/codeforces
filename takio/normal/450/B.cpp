#include <cstring>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

long long md(long long n){
    long long mod = 1e9 + 7;
    return (n % mod + mod) % mod;
}

int main () {
    long long x, y, n;
    cin >> x >> y >> n;
    long long z = y - x;
    n %= 6;
//    cout << n << ' ' << z << endl;
    if (n == 1) cout << md(x);
    else if (n == 2) cout << md(y);
    else if (n == 3) cout << md(z);
    else if (n == 4) cout << md(-x);
    else if (n == 5) cout << md(-y);
    else cout << md(-z);
}