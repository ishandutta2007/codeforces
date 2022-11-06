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

int main() {
    //ios::sync_with_stdio(false);
    cin >> n;
    cout << (base)pow(((n) * (n - 1) * (n - 2) * (n - 3)* (n - 4) / 120), 2) * 120;
}