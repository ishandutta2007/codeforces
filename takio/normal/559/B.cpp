#include <bits/stdc++.h>
#define lson ls[rt], l, m
#define rson rs[rt], m + 1, r
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second

using namespace std;

const int N = 200100;
char s[N], t[N];

int jug (char s[], char t[], int len) {
    for (int i = 0; i < len; i++)
        if (s[i] < t[i]) return -1;
        else if (s[i] > t[i]) return 1;
    return 1;
}

void solve (char s[], int len) {
    if (len % 2) return;
    len /= 2;
    solve (s, len);
    solve (s + len, len);
    if (jug (s, s + len, len) < 0) return;
    for (int i = 0; i < len; i++)
        swap (s[i], s[i + len]);
}

int main () {
    scanf ("%s%s", s, t);
    int len = strlen (s);
    solve (s, len);
    solve (t, len);
    if (strcmp (s, t) == 0) cout << "YES";
    else cout << "NO";
}