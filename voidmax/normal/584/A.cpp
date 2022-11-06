#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a; i > b; --i)
#define pb push_back
#define inf 1e9
#define x first
#define y second

using namespace std;

int n, t;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> t;
    if (n == 1) {
        if (t == 10) {
            cout << -1 << endl;
        } else {
            cout << t << endl;
        }
        return 0;
    }
    while (n > 0) {
        if (n == 1) {
            cout << 0 << endl;
            break;
        }
        --n; cout << t;
        if (t == 10) --n;
    }
}