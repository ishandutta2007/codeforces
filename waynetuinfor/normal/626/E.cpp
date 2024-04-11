#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
const long double inf = 1e9;
int x[maxn], n;
long long s[maxn];

long double f1(int m, int k) {
    long double su = x[m] + s[m - 1] - s[m - 1 - k] + s[n] - s[n - k];
    int c = 1 + k + k;
    return su / c - x[m];
}

long double f2(int m1, int m2, int k) {
    long double su = x[m1] + x[m2] + s[m1 - 1] - s[m1 - 1 - k] + s[n] - s[n - k];
    int c = 2 + k + k;
    return su / c - (x[m1] + x[m2]) * 1.0 / 2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    sort(x + 1, x + 1 + n);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + x[i];
    long double ans1 = -inf;
    int p1 = -1, z1 = -1;
    for (int i = 1; i <= n; ++i) {
        int d = 31, j = 0;
        while (d--) if (i - 1 - (j + (1 << d)) + 1 >= 1 && n - (j + (1 << d)) + 1 > i) {
            int to = j + (1 << d);
            if (f1(i, to - 1) < f1(i, to)) j += (1 << d);
        }
        long double fi = f1(i, j);
        if (fi > ans1) ans1 = fi, p1 = i, z1 = j;
    }  
    long double ans2 = -inf;
    int p2 = -1, z2 = -1;
    for (int i = 1; i < n; ++i) {
        int d = 31, j = 0;
        while (d--) if (i - 1 - (j + (1 << d)) + 1 >= 1 && n + 1 - (j + (1 << d)) > i + 1) {
            int to = j + (1 << d);
            if (f2(i, i + 1, to - 1) < f2(i, i + 1, to)) j += (1 << d);
        }
        long double fi = f2(i, i + 1, j);
        if (fi > ans2) ans2 = fi, p2 = i, z2 = j;
    }
    if (ans1 > ans2) {
        cout << z1 * 2 + 1 << endl;
        for (int i = p1 - z1; i < p1; ++i) cout << x[i] << ' ';
        cout << x[p1] << ' ';
        for (int i = n + 1 - z1; i <= n; ++i) cout << x[i] << ' ';
        cout << endl;
    } else {
        cout << z2 * 2 + 2 << endl;
        for (int i = p2 - z2; i < p2; ++i) cout << x[i] << ' ';
        cout << x[p1] << ' ' << x[p1 + 1] << ' ';
        for (int i = n + 1 - z2; i <= n; ++i) cout << x[i] << ' ';
        cout << endl;
    }
    return 0;
}