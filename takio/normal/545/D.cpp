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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
    }
    sort (a + 1, a + 1 + n);
    LL sum = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= sum) {
            res++;
            sum += a[i];
        }
    }
    cout << res <<endl;
}