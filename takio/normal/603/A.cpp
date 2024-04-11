#include <bits/stdc++.h>
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pii pair <LL, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100;

int n, res = 0, c[5];
char s[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n;
    scanf ("%s", s + 1);
    for (int i = 1; s[i]; i++) {
        if (i == 1 || s[i] != s[i - 1]) res++;
        if (i != 1 && s[i] == s[i - 1]) c[s[i] - '0']++;
    }
    if (c[0] + c[1] >= 2) cout << res + 2;
    else if (c[0] || c[1]) cout << res + 1;
    else cout << res;
}