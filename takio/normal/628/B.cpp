#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
#define ULL unsigned long long
using namespace std;

const int N = 300020, mod = 1e9 + 7;

char s[N];
int c[4], t[4];

int main () {
//    freopen ("in.txt", "r", stdin);
    scanf ("%s", s);
    LL res = 0;
    c[0]++;
    int now = 0;
    for (int i = 0; s[i]; i++) {
        now = (now * 10 + s[i] - '0') % 4;
        res += c[now];
        c[now]++;
        memset (t, 0, sizeof t);
        for (int i = 0; i < 4; i++) {
            t[i * 10 % 4] += c[i];
        }
        memcpy (c, t, sizeof t);
    }
    cout << res << endl;
}