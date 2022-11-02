#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100010;
//const ULL 1LL = 1;

int x[N], y[N];

LL sqr (LL x) { return x * x; }

LL dis (int a, int b) {
    return sqr (x[a] - x[b]) + sqr (y[a] - y[b]);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf ("%d%d", &x[i], &y[i]);
    LL mn = -1;
    int a = 0, b = 0;
    for (int i = 2; i <= n; i++) {
        if (mn == -1 || dis (1, i) < mn) {
//            cout << i << ' ' << dis (1, i) << endl;
            mn = dis (1, i);
            a = i;
        }
    }
    mn = -1;
    for (int i = 2; i <= n; i++) if (i != a) {
        if (1LL * (x[a] - x[1]) * (y[a] - y[i]) != 1LL * (y[a] - y[1]) * (x[a] - x[i])) {
//            cout << i << endl;
            LL tmp = ((1LL * x[1] * y[a] - 1LL * x[a] * y[1]) + (1LL * x[a] * y[i] - 1LL * x[i] * y[a]) + (1LL * x[i] * y[1] - 1LL * x[1] * y[i]));
//            cout << i << ' ' << tmp <<endl;
            if (tmp < 0) tmp = -tmp;
            if (mn == -1 || tmp < mn) {
                mn = tmp;
                b = i;
            }
        }
    }
    cout << 1 << ' ' << a << ' ' << b << endl;
}