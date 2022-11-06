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

long double a, b;

int main() {
    //ios::sync_with_stdio(false);
    cin >> a >> b;
    cout << fixed << a * pow((long double)1.000000011, b) << endl;
}