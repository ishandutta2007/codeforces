#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <base, base>
#define x first
#define y second

using namespace std;

typedef unsigned long long base;

base a1, a2, b1, b2;
int main() {
    //ios::sync_with_stdio(false);
    cin >> a1 >> a2 >> b1 >> b2;
    b1 -= a1 - 1;
    b2 -= a2 - 1; b2 = (b2 + 1) / 2;
    if (!(b1 & 1)) {
        cout << b1 * b2 << endl;
        return 0;
    }
    cout << b1 * b2 - b1 / 2 << endl;
}