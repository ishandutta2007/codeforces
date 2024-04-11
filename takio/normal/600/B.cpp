#include <bits/stdc++.h>
using namespace std;

const int N = 210000;
int a[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, x;
    cin >> n >> m;
    multiset <int> st;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
    }
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= m; i++) {
        scanf ("%d", &x);
        printf ("%d ", upper_bound (a + 1, a + 1 + n, x) - a - 1);
    }
}