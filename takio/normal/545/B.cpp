#include <bits/stdc++.h>

#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
using namespace std;

const int N = 100100;

char s[N], t[N], res[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    scanf ("%s%s", s, t);
    int cnt = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] != t[i]) cnt++;
    }
    if (cnt & 1) cout << "impossible\n";
    else {
        int flag = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == t[i]) res[i] = s[i];
            else {
                if (flag) res[i] = s[i];
                else res[i] = t[i];
                flag ^= 1;
            }
        }
        printf ("%s\n", res);
    }
}