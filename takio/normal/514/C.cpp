#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define getm int m = (l + r) >> 1
#define LL long long
#define ULL unsigned long long
#define pii pair <LL, LL>

using namespace std;

const int N = 600100;
const ULL p1 = 13, p2 = 17;
const LL mod1 = 1e9 + 7, mod2 = 1e9 + 7;

map <pii, int> mp;
char s[N];
ULL f1[N], f2[N];

pii gethash () {
    ULL hash1 = p1, hash2 = p2;
    for (int i = 0; s[i]; i++) {
        hash1 += s[i];
        (hash1 *= p1) %= mod1;
        hash2 += s[i];
        (hash2 *= p2) %= mod2;
    }
//    cout << hash1 << ' ' << hash2 << endl;
    return pii (hash1, hash2);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    f1[0] = f2[0] = 1;
    for (int i = 1; i < N; i++) {
        f1[i] = f1[i - 1] * p1 % mod1;
        f2[i] = f2[i - 1] * p2 % mod2;
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf ("%s", s);
        mp[gethash ()] = 1;
    }
    while (m--) {
        scanf ("%s", s);
        pii tmp = gethash();
        int len = strlen (s);
        for (int i = 0; i < len; i++) {
            tmp.first -= f1[len - i] * s[i] % mod1, tmp.second -= f2[len - i] * s[i] % mod2;
            if (tmp.first < 0) tmp.first += mod1;
            if (tmp.second < 0) tmp.second += mod2;
            char c = s[i];
            for (char j = 'a'; j <= 'c'; j++) if (c != j) {
                if (mp.find (pii ((tmp.first + f1[len - i] * j) % mod1, (tmp.second + f2[len - i] * j) % mod2)) != mp.end()) {
                    printf ("YES\n");
                    goto x;
                }
            }
            tmp.first += f1[len - i] * s[i] % mod1, tmp.second += f2[len - i] * s[i] % mod2;
            if (tmp.first >= mod1) tmp.first -= mod1;
            if (tmp.second >= mod2) tmp.second -= mod2;
        }
        printf ("NO\n");
        x:;
    }
}