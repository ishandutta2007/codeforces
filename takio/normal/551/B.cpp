#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r

using namespace std;

const int N = 100100;
char a[N], b[N], c[N];
int ca[300], cb[300], cc[300], t[300];

int cal (int x) {
    int mn = 1e9;
    for (int i = 0; i < 26; i++) {
        LL t = ca[i] - 1LL * x * cb[i];
        if (t < 0) return -1;
        if (cc[i]) mn = min (mn, (int)t / cc[i]);
    }
    return mn;
}

int main () {
    scanf ("%s%s%s", a, b, c);
    for (int i = 0; a[i]; i++) ca[a[i] - 'a']++;
    for (int i = 0; b[i]; i++) cb[b[i] - 'a']++;
    for (int i = 0; c[i]; i++) cc[c[i] - 'a']++;
    int r1 = 0, r2 = 0;
    for (int i = 0; i <= 100000; i++) {
        int tmp = cal (i);
        if (tmp == -1) continue;
        if (tmp + i > r1 + r2) {
            r1 = i;
            r2 = tmp;
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= ca[i] - r1 * cb[i] - r2 * cc[i]; j++)
            printf ("%c", (char)(i + 'a'));
    }
    while (r1--) {
        printf ("%s", b);
    }
    while (r2--) {
        printf ("%s", c);
    }
}