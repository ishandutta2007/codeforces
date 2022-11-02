#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const int N = 1001000, mod = 100017, mod1 = 1e9 + 9, mod2 = 1e9 + 7, p1 = 19, p2 = 23, M = 10010;

char s[N];
string t[100100];
int dp[M];
LL h1[M], h2[M], f1[M], f2[M];

struct hashmap {
    pii key[N];
    int val[N], head[mod], nx[N], tot;
    void init () {
        memset (head, -1, sizeof head);
        tot = 0;
    }
    void ins (pii x, int y) {
        int h = x.xx * x.yy % mod;
        key[tot] = x;
        val[tot] = y;
        nx[tot] = head[h];
        head[h] = tot++;
    }
    int qry (pii x) {
        int h = x.xx * x.yy % mod;
        for (int i = head[h]; ~i; i = nx[i]) {
            if (key[i] == x) return val[i];
        }
        return 0;
    }
} mp;

pii gethash (int x) {
    LL h1 = 0, h2 = 0;
    int len = t[x].length();
//    cout << len << endl;
    for (int i = 0; i < len; i++) {
        char tmp = t[x][i];
        if ('A' <= tmp && tmp <= 'Z') tmp -= 'A' - 'a';
        h1 = (h1 * p1 + tmp) % mod1;
        h2 = (h2 * p2 + tmp) % mod2;
    }
    return pii (h1, h2);
}

pii gethash (int l, int r) {
    return pii ((h1[r] - h1[l - 1] * f1[r - l + 1] % mod1 + mod1) % mod1, (h2[r] - h2[l - 1] * f2[r - l + 1] % mod2 + mod2) % mod2);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n;
    f1[0] = f2[0] = 1;
    for (int i = 1; i < M; i++) f1[i] = f1[i - 1] * p1 % mod1, f2[i] = f2[i - 1] * p2 % mod2;
//    scanf ("%s", s + 1);
    cin >> s + 1;
    for (int i = 1, j = n; i < j; i++, j--) swap (s[i], s[j]);
//    cout << s + 1 << endl;
//    return 0;
    for (int i = 1; i <= n; i++) {
        h1[i] = (h1[i - 1] * p1 + s[i]) % mod1;
        h2[i] = (h2[i - 1] * p2 + s[i]) % mod2;
    }
    cin >> m;
    mp.init ();
//    return 0;
    for (int i = 1; i <= m; i++) {
        cin >> t[i];
        mp.ins (gethash (i), i);
//        cout << gethash (i).xx <<' ' << gethash (i).yy <<endl;
    }
//    return 0;
//    cout << gethash (7, 11).xx << ' ' << gethash (7, 11).yy << endl;
//    cout << gethash (1, 6).xx << ' ' << gethash (1, 6).yy << endl;
//    cout << gethash (2, 7).xx << ' ' << gethash (2, 7).yy << endl;
    memset (dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 0; i < n; i++) if (dp[i]) {
        for (int j = 1; j <= 1000 && i + j <= n; j++) {
            int tmp = mp.qry (gethash (i + 1, i + j));
            if (tmp) {
//                cout << i + 1 << ' ' << i + j << endl;
                dp[i + j] = tmp;
            }
        }
    }
//    return 0;
    int now = n;
    while (now) {
        cout << t[dp[now]] << ' ';
        now -= t[dp[now]].length();
    }
}