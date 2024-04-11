#include <cstdio>
#include <iostream>
#define LL long long
using namespace std;

const LL MOD = 1000000007;

int a, b, c;

int solve () {
    if (c == 0) return a == b;
    if (c > 0) return a <= b && (b - a) % c == 0;
    if (c < 0) return a >= b && (a - b) % (-c) == 0;
}

int main () {
    cin >> a >> b >> c;
    if (solve ()) cout << "yes\n";
    else cout << "no\n";
}