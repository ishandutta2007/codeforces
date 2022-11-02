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

int sum(long long x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    // freopen("input.txt", "r", stdin);
    long long a, b, c;
    vector<long long> v;
    cin >> a >> b >> c;
    for (int s = 1; s <= 9 * 9; s++) {
        long long r = 1;
        for (int i = 0; i < a; i++) {
            r = r * s;
        }
        r = r * b + c;
        if ((r <= 0) || (r >= 1000000000)) {
            continue;
        }
        if (sum(r) == s) {
            v.push_back(r);
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    if (v.size() == 0) {
        return 0;
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}