#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second

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
    int mx = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] <= mx) b[i] = mx - a[i] + 1;
        else b[i] = 0;
        mx = max (mx, a[i]);
    }
    for (int i = 1; i <= n; i++) printf ("%d ", b[i]);
}