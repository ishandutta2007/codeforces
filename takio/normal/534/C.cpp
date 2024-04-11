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

const int N = 200100;

int a[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    LL m, sum = 0;
    cin >> n >> m;
    for (int i = 1 ;i <= n; i++) {
        scanf ("%d", &a[i]);
        sum += a[i];
    }
    if (n == 1) {
        cout << a[1] - 1;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        int t1 = max (m - (sum - a[i]), 1LL);
        int t2 = min (m - (n - 1), (LL)a[i]);
//        cout << t1 << ' ' << t2 << endl;
        printf ("%d ", max (a[i] - (t2 - t1 + 1), 0));
    }
}