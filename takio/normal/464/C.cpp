#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;

const int N = 500100, B = 50, mod = 1e9 + 7;
char n[N], s[N], c[N];
LL num[B], bit[B], l[N], r[N];
int q;

int main () {
//    freopen ("in.txt", "r", stdin);
    scanf ("%s", n);
    cin >> q;
    for (int i = 0; i <= 9; i++) {
        num[i] = i, bit[i] = 10;
    }
    int sn = 0;
    for (int i = 1; i <= q; i++){
        cin >> c[i];
        l[i] = sn;
        scanf ("%s", s + sn);
        r[i] = sn + strlen (s + sn) - 1;
        sn += strlen (s + sn);
    }
//    cout << s << endl;
    for (int k = q; k >= 1; k--) {
        LL tb = 1, tn = 0;
        for (int i = l[k] + 2; i <= r[k]; i++) {
            int t = s[i] - '0';
//            cout << s[i];
            (tn *= bit[t]) %= mod;
            (tn += num[t]) %= mod;
            (tb *= bit[t]) %= mod;
        }
//        cout << endl;
        int t = c[k] - '0';
        num[t] = tn;
        bit[t] = tb;
//        cout << t << ' ' << tb << ' ' << tn << endl;
    }
    int len = strlen (n);
    LL res = 0;
    for (int i = 0; i < len; i++) {
        int t = n[i] - '0';
        (res *= bit[t]) %= mod;
        (res += num[t]) %= mod;
    }
    cout << res << endl;
}