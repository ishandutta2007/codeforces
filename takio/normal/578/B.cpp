#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define pii pair <LL, LL>

using namespace std;

const int N = 200100;
const ULL M = 1LL << 33;
const double eps = 1e-6;

int a[N];
LL b[N], c[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, k, x;
    cin >> n >> k >> x;
    LL y = 1;
    while (k--) y *= x;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] | a[i];
    }
    for (int i = n; i >= 1; i--) {
        c[i] = c[i + 1] | a[i];
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        res = max (res, b[i - 1] | c[i + 1] | (1LL * a[i] * y));
    }
    cout << res << endl;
}