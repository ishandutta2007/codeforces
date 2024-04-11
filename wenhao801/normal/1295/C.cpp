#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 200200;

int T;

char s[MAXN], t[MAXN];
int ls, lt;

int nex[MAXN][33] = {};
int cnt[33] = {};
int cnt2[33] = {};

int main () {
    T = read();
    while (T--) {
        scanf("%s", s + 1); scanf("%s", t + 1);
        ls = strlen(s + 1), lt = strlen(t + 1);
        int i, j;
        for (i = 1; i <= 26; i++) cnt[i] = cnt2[i] = 0;
        for (i = 1; i <= ls; i++) cnt[s[i] - 'a' + 1]++;
        for (i = 1; i <= lt; i++) cnt2[t[i] - 'a' + 1]++;
        bool f = false;;
        for (i = 1; i <= 26; i++) if (cnt2[i] > 0 && cnt[i] == 0) {puts("-1"); f = true; break; }
        if (f) continue;
        for (i = 1; i <= 26; i++) nex[ls][i] = ls + 1;
        for (i = ls; i >= 1; i--) {
            nex[i - 1][s[i] - 'a' + 1] = i;
            for (j = 1; j <= 26; j++) {
                if (j == s[i] - 'a' + 1) continue;
                else nex[i - 1][j] = nex[i][j];
            }
        }
        //for (i = 0; i <= ls; i++) printf("%d %d\n", nex[i][25], nex[i]['t' - 'a' + 1]);
        int now = 0, ans = 1;
        for (i = 1; i <= lt; i++) {
            now = nex[now][t[i] - 'a' + 1];
            if (now == ls + 1) now = nex[0][t[i] - 'a' + 1], ans++;
            //cout << now << endl;
        }
        printf("%d\n", ans);
    }
    return 0;
}