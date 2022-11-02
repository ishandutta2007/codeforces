#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cstring>
#include<algorithm>
#define LL long long
#define pii pair <LL, LL>
using namespace std;

const int N = 1000100, p1 = 17, p2 = 19, mod1 = 1e9 + 7, mod2 = 1e9 + 9;

LL f1[N], f2[N], h1[N], h2[N];
char p[N];
int is[N];

pii gethash (int l, int r) {
    LL hash1 = ((h1[r] - h1[l - 1] * f1[r - l + 1]) % mod1 + mod1) % mod1;
    LL hash2 = ((h2[r] - h2[l - 1] * f2[r - l + 1]) % mod2 + mod2) % mod2;
//    cout << l <<' ' << r << ' ' << hash1 <<' ' << hash2 << endl;
    return pii (hash1, hash2);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    f1[0] = f2[0] = 1;
    for (int i = 1; i < N; i++) {
        f1[i] = f1[i - 1] * p1 % mod1;
        f2[i] = f2[i - 1] * p2 % mod2;
    }
//    cout << f1[1] << ' ' << f2[1] << endl;
    int n, m;
    cin >> n >> m;
    scanf ("%s", p + 1);
    int len = strlen (p + 1);
    for (int i = 1; i <= len; i++) {
        (h1[i] = h1[i - 1] * p1 + p[i]) %= mod1;
        (h2[i] = h2[i - 1] * p2 + p[i]) %= mod2;
//        cout << h1[i] << ' ' << h2[i] << endl;
    }
    int x;
    for (int i = 1; i <= m; i++) {
        scanf ("%d", &x);
        is[x] = 1;
    }
    int last = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (is[i]) {
            if (last && last + len > i) {
                int l = len - (i - last);
                if (gethash (1, l) != gethash (i - last + 1, len)) {
//                    cout << last << ' ' << i << endl;
//                    cout << 1 << ' ' << l << ' ' << i - last + 1 << ' ' << len <<endl;
                    printf ("0");
                    return 0;
                }
            }
            last = i;
        }
        if (!last || last + len <= i) cnt++;
    }
    LL res = 1;
    for (int i = 1; i <= cnt; i++) (res *= 26) %= mod1;
    cout << res <<endl;
}