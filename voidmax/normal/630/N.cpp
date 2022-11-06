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

typedef long double base;

base a, b, c;

int main() {
    //ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    base D = b * b - 4 * a * c;
    base M1 = (-b + sqrt(D)) / 2 / a;
    base M2 = (-b - sqrt(D)) / 2 / a;
    cout << fixed << max(M1, M2) << endl;
    cout << fixed << min(M1, M2) << endl;
}