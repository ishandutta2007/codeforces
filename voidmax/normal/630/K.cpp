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
base ans = 0;
int main() {
    //ios::sync_with_stdio(false);
    cin >> n;
    ans += n / 2 + n / 3 - n / 6 + n / 5 - n / 10 - n / 15 + n / 30 + n / 7 - n / 14 - n / 21 - n / 35 + n / 42 + n / 70 + n / 105 - n / 210;
    cout << n - ans << endl;
}