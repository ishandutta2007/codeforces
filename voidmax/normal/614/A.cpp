#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second

using namespace std;

typedef long long base;

int cnt;
base L, R, p, ps = 1;
long double now;
bool OK = true;

int main() {
    ios::sync_with_stdio(false);
    cin >> L >> R >> p;
    while (true) {
        if (L <= ps && ps <= R) {
            cout << ps << ' ';
            OK = false;
        }
        ++cnt; now = ps; now *= p;
        if (now > R) break; ps *= p;
    }
    if (OK) cout << -1 << endl;
}