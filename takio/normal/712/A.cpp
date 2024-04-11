#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
using namespace std;

const int N = 100100, eps = 1e-6;
LL a[N], b[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%I64d", &a[i]);
    }
    LL sum = 0;
    for (int i = n; i >= 1; i--) {
        b[i] = a[i] + sum;
        sum = b[i] - sum;
    }
    for (int i = 1; i <= n; i++) {
        printf ("%I64d ", b[i]);
    }
}