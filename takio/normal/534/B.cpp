#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#define pii pair <int, int>
#define xx first
#define yy second
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r

using namespace std;

int main () {
    int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;
    int all = 0, res = 0;
    while (all < t) {
        if (v1 < v2) swap (v1, v2);
//        cout << v2 << endl;
        res += v2;
        v2 += d;
        all++;
    }
    cout << res << endl;
}