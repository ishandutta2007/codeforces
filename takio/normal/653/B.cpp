#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pis pair <int, string>
using namespace std;

const int N = 200100, M = 1000010, mod = 1e9 + 7;

int r, n;
char mp[300][300], s[5], t[5];

int jug (string s) {
    if (s == "a") return 1;
    int now = s[0];
    for (int i = 1; s[i]; i++) {
        if (!mp[now][s[i]]) {
            return 0;
//            string t = s.substr(0, i) + mp[s[i]][s[i + 1]] + s.substr (i + 2, s.length () - i - 2);
//            if (jug (t)) return 1;
        }
        now = mp[now][s[i]];
    }
    return now == 'a';
}

void dfs (int k, string s) {
    if (k == n) {
//        cout << s << endl;
        if (jug (s)) {
//            cout << s << endl;
            r++;
        }
        return;
    }
    for (char i = 'a'; i <= 'f'; i++) {
        dfs (k + 1, s + i);
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int q;
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        scanf ("%s%s", s, t);
        mp[s[0]][s[1]] = t[0];
    }
    dfs (0, "");
    cout << r << endl;
//    return
}