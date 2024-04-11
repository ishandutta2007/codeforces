#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <ctime>
#include <cmath>
#include <queue>
#define pii pair <int, int>
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define type double

using namespace std;

pii a[5010];

int main () {
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d", &a[i].first, &a[i].second);
    }
    sort (a + 1, a + 1 + n);
    int f = a[1].second;
    for (int i = 2; i <= n; i++) {
        if (a[i].second >= f) f = a[i].second;
        else f = a[i].first;
    }
    cout << f << endl;
}