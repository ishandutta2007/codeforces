#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 5050;
int n, m;
map <string, int> mp;

int ch[MAXN][2], opr[MAXN], len[MAXN];
string c[MAXN][2];
int now[MAXN];

bool val (int bit, int x, bool cc, bool cur) {
    if (!ch[x][cc]) return c[x][cc][bit] - '0';
    else if (ch[x][cc] == n + 1) return cur;
    else return now[ch[x][cc]];
}
bool calc (int bit, int x, bool cur) {
    if (opr[x] == 0) return val(bit, x, 0, cur) | val(bit, x, 1, cur);
    if (opr[x] == 1) return val(bit, x, 0, cur) & val(bit, x, 1, cur);
    return val(bit,x , 0, cur) ^ val(bit, x, 1, cur);
}
string tmp; char mx[MAXN], mn[MAXN];

int main () {
    n = read(), m = read();
    int i, j;
    mp["?"] = n + 1; len[n + 1] = 1;
    for (i = 1; i <= n; i++) {
        cin >> tmp;
        mp[tmp] = i; len[i] = tmp.size();
        cin >> tmp; getline(cin, tmp); tmp = tmp.substr(1);
        if (tmp[0] == '0' || tmp[0] == '1') {
            if (tmp.size() == m) { c[i][0] = c[i][1] = tmp; opr[i] = 0; continue; }
            c[i][0] = tmp; 
            tmp = tmp.substr(m + 1);
        }
        else {
            for (j = 1; tmp[j] != ' '; j++);
            ch[i][0] = mp[tmp.substr(0, j)], tmp = tmp.substr(j + 1);
        }
        if (tmp[0] == 'O') opr[i] = 0, tmp = tmp.substr(3);
        else if (tmp[0] == 'A') opr[i] = 1, tmp = tmp.substr(4);
        else opr[i] = 2, tmp = tmp.substr(4);
        
        if (tmp[0] == '0' || tmp[0] == '1') c[i][1] = tmp; else ch[i][1] = mp[tmp];
    }
    // for (int x = 1; x <= n; x++) {
    //     printf("node %d: opr = %d\n", x, opr[x]);
    //     if (ch[x][0]) cout << ch[x][0] << endl; else cout << c[x][0] << endl;
    //     if (ch[x][1]) cout << ch[x][1] << endl; else cout << c[x][1] << endl;
    // }
    for (i = 0; i < m; i++) {
        int p0 = 0, p1 = 0;
        memset(now, 0, sizeof now);
        for (j = 1; j <= n; j++) {
            now[j] = calc(i, j, 0);
            p0 += now[j];
        }
        memset(now, 0, sizeof now);
        for (j = 1; j <= n; j++) {
            now[j] = calc(i, j, 1);
            p1 += now[j];
        }
        if (p0 == p1) mx[i] = mn[i] = '0';
        else if (p0 < p1) mx[i] = '1', mn[i] = '0';
        else mx[i] = '0', mn[i] = '1';
    }
    for (i = 0; i < m; i++) cout << mn[i]; cout << endl;
    for (i = 0; i < m; i++) cout << mx[i]; cout << endl;
    return 0;
}