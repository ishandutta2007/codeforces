#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const int N = 501000;

int a[N], b[N], c[N];
LL d[N];

int solve () {
    int n;
    LL s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &b[i]);
        s += b[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &c[i]);
        s += c[i];
    }
    if (s % (n * 2)) return 0;
    s /= n * 2;
//    cout << s << endl;
    for (int i = 1; i <= n; i++) {
        a[i] = b[i] + c[i] - s;
        if (a[i] % n) return 0;
        a[i] /= n;
        for (int j = 0; j < 32; j++) if (a[i] & (1 << j)) d[j]++;
    }
//    for (int i = 1; i <= n; i++) printf ("%d ", a[i]);
    for (int i = 1; i <= n; i++) {
        LL s1 = 0, s2 = 0;
        for (int j = 0; j < 32; j++) {
            if (a[i] & (1 << j)) {
                s1 += d[j] << j;
                s2 += (LL)n << j;
            } else {
                s2 += d[j] << j;
            }
        }
//        cout << s1 << ' ' << s2 << endl;
        if (s1 != b[i] || s2 != c[i]) return 0;
    }
    for (int i = 1; i <= n; i++) printf ("%d ", a[i]);
    return 1;
}


int main () {
//    freopen ("in.txt", "r", stdin);
//    for (int i = 0; i <= 1000; i++){
//        for (int j = 0; j <= 1000; j++) {
////            cout << i + j << ' ' << ((i & j) << 1) + (i ^ j) << endl;
//            assert (i + j == (i & j) + (i | j));
//            assert (i + j == ((i & j) << 1) + (i ^ j));
////            assert (i + j == ((i & j) << 1) + (i ^ j));
//        }
//    }
    if (solve () == 0) cout << -1;
}