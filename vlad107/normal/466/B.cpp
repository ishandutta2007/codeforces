#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>

using namespace std;

long long n, a, b;

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> a >> b;
    n = 6LL * n;
    bool sw = false;
    if (a > b) {
        sw = true;
        swap(a, b);
    }
    long long res = 1000000000000000001LL, aa, bb;
    for (long long x = 1; (x - 1) * (x - 1) <= n; x++) {
        //x * y >= n
        long long z = max(x, a);
        long long y = (n + z - 1) / z;
        y = max(y, b);
        long long cur = z * y;
        if (cur < res) {
            res = cur;
            aa = z;
            bb = y;
        }
    }
    if (sw) {
        swap(aa, bb);
    }
    cout << aa * bb << endl;
    cout << aa << " " << bb << endl;
}