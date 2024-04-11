#include <bits/stdc++.h>

#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
using namespace std;

const int N = 100100;

int a[N], b[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, res = 0;
    cin >> n;
    int now = -2e9 - 10;
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d", &a[i], &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1 || now < a[i] - b[i]) {
            res++;
            now = a[i];
        } else if (i == n || a[i] + b[i] < a[i + 1]) {
            now = a[i] + b[i];
            res++;
        } else {
            now = a[i];
        }
    }
    cout << res << endl;
}