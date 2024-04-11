#include <bits/stdc++.h>
#define pii pair <int, int>
#define pic pair <int, char>
#define psi pair <string, int>
#define piii pair <pii, int>
#define UINT unsigned int
#define LL long long
#define xx first
#define yy second
using namespace std;

const int N = 210000;
const int mod = 1e9 + 7;

LL c[N], L[N], R[N];

LL mypow(LL x, LL y, LL m) {
    LL r = 1;
    while (y) {
        if (y & 1) (r *= x) %= m;
        (x *= x) %= m;
        y >>= 1;
    }
    return r;
}

int main () {
//    freopen("in.txt", "r", stdin);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &x);
        c[x]++;
    }
    L[0] = R[N - 1] = 1;
    for (int i = 1; i < N; i++) {
        L[i] = L[i - 1] * (c[i] + 1) % (mod - 1);
    }
    for (int i = N - 2; i >= 1; i--) {
        R[i] = R[i + 1] * (c[i] + 1) % (mod - 1);
    }
    LL r = 1;
    for (int i = 1; i < N; i++) if (c[i]) {
//        cout << i << ' ' << mypow(i, c[i] * (c[i] + 1) / 2, mod) << endl;
        r *= mypow(mypow(i, c[i] * (c[i] + 1) / 2, mod), L[i - 1] * R[i + 1] % (mod - 1), mod);
        r %= mod;
    }
    cout << r << endl;
}