#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 210000;
int x[N], y[N], p;

int cal (int a, int b) { return a / b; }

long double solve (int i, int j) {
    LL la = y[i] - x[i] + 1;
    LL lb = y[j] - x[j] + 1;
    LL a = (cal (y[i], p) - cal (x[i] - 1, p));
    LL b = (cal (y[j], p) - cal (x[j] - 1, p));
//    cout << 1.0 * (la - a) * (lb - b) / (la * lb) <<' ';;
//    cout << i << ' ' << j << ' ' << 1.0 - (long double)((la - a) * (lb - b)) / (la * lb) << endl;
//    cout << (la - a) * (lb - b) << ' ' << (la * lb) << endl;;
    return 1.0 - (long double)((la - a) * (lb - b)) / (la * lb);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d", &x[i], &y[i]);
    }
    long double res = 0;
    for (int i = 1; i < n; i++) {
        res += solve (i, i + 1);
    }
    res += solve (1, n);
    printf ("%.10f\n", (double )(res * 2000));
}