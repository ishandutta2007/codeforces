#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 410;
const LL INF = 1LL << 61;

int nx[N][26], fail[N], rt = 0, tot = 0, a[N];
LL d[65][N], mp[65][N][N], ed[N], vis[N][N];

int newnode () {
    memset (nx[tot], -1, sizeof nx[tot]);
    ed[tot] = 0;
    return tot++;
}

void insert (string s, int c) {
    int now = rt;
    for (int i = 0; i < s.length (); i++) {
        if (nx[now][s[i] - 'a'] == -1) nx[now][s[i] - 'a'] = newnode ();
        now = nx[now][s[i] - 'a'];
    }
    ed[now] += c;
}

void build () {
    queue <int> q;
    fail [rt] = rt;
    for (int i = 0; i < 26; i++)
        if (nx[rt][i] == -1) nx[rt][i] = rt;
        else { fail[nx[rt][i]] = rt; q.push (nx[rt][i]); }
    while (!q.empty ()) {
        int now = q.front ();
        q.pop();
        for (int i = 0; i < 26; i++) {
            if (nx[now][i] == -1) {
                nx[now][i] = nx[fail[now]][i];
            } else {
                fail [nx[now][i]] = nx[fail[now]][i];
                ed[nx[now][i]] += ed[nx[fail[now]][i]];
                q.push (nx[now][i]);
            }
        }
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    LL l;
    cin >> n >> l;
    rt = newnode ();
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        insert (s, a[i]);
    }
    build ();
//    int now = 0;
    for (int i = 0; i < tot; i++) {
        for (int j = 0; j < 26; j++) {
//            if (nx[i][j]) cout << i << ' ' << j << ' ' << nx[i][j] << ' ' << ed[nx[i][j]] << endl;
            mp[0][i][nx[i][j]] += ed[nx[i][j]];
            vis[i][nx[i][j]] = 1;
        }
    }
    for (int i = 0; i < tot; i++)
        for (int j = 0; j< tot; j++)
            if (vis[i][j] == 0) {
                mp[0][i][j] = -INF;
            }
    for (int i = 0; i < tot; i++) d[0][i] = -INF;
    d[0][0] = 0;
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < tot; j++) d[i + 1][j] = -INF;
        if (l & (1LL << i)) {
//            for (int j = 0; j < tot; j++)
//                for (int k = 0; k < tot; k++) cout << j << ' ' << k << ' '<< mp[i][j][k] << endl;
            for (int j = 0; j < tot; j++) {
                for (int k = 0; k < tot; k++) {
                    d[i + 1][k] = max (d[i + 1][k], d[i][j] + mp[i][j][k]);
                }
            }
        } else {
            for (int j = 0; j < tot; j++) d[i + 1][j] = d[i][j];
        }
        for (int j = 0; j < tot; j++) {
            for (int k = 0; k < tot; k++) {
                mp[i + 1][j][k] = -INF;
            }
        }
        for (int j = 0; j < tot; j++) {
            for (int k = 0; k < tot; k++) {
                for (int l = 0; l < tot; l++) {
                    mp[i + 1][k][l] = max (mp[i + 1][k][l], mp[i][k][j] + mp[i][j][l]);
                }
            }
        }
//        now ^= 1;
    }
    LL res = 0;
    for (int i = 0; i < tot; i++) res = max (res, d[60][i]);
    cout << res << endl;
}