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

int n;

int res(int i) {
    if (i == 0) {
        return 0;
    }
    if (i < 5) return 1;
    return res(i - 5) + 1;
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cout << res(n);
}