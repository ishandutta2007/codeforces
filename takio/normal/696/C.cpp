#include<cstdio>
#include <set>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<map>
#define LL long long
using namespace std;

const int mod = 1e9 + 7;
int pm (LL x, LL y, int mod) {
    LL r = 1;
    while (y) {
        if (y & 1) (r *= x) %= mod;
        (x *= x) %= mod;
        y >>= 1;
    }
    return r;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    LL x = 1, a;
//    int a;
    for (int i = 1; i <= n; i++) {
        scanf ("%I64d", &a);
        a %= mod - 1;
        x *= a;
//        cout << x << endl;
        x %= mod - 1;
    }
    x = (x - 1 + mod - 1) % (mod - 1);
//    cout << x << endl;
    LL tmp = pm (2, x, mod);
    LL tmp2 = tmp;
    if (x & 1) tmp2++; else tmp2--;
    tmp2 += mod;
    tmp2 %= mod;
    cout << tmp2 * pm (3, mod - 2, mod) % mod << '/' << tmp << endl;
}