#include <bits/stdc++.h>
#define lson ls[rt], l, m
#define rson rs[rt], m + 1, r
#define pii pair <int, int>
#define xx first
#define yy second
#define LL long long

using namespace std;

int main () {
    int a[8];
    for (int i = 1; i <= 6; i++) cin >> a[i];
    LL res = 1LL * (a[1] + a[2] + a[3]) * (a[1] + a[2] + a[3]) - a[1] * a[1] - a[3] * a[3] - a[5] * a[5];
    cout << res << endl;
}