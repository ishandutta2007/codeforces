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

typedef long long base;

base n;
base ans;

int main() {
    //ios::sync_with_stdio(false);
    cin >> n;
    ans += (base)12 * pow(4, (n - 3)); ans *= 2;
    if (n > 3) ans += (base)36 * pow((base)4, (n - 4)) * (n - 3);
    cout << ans << endl;
}