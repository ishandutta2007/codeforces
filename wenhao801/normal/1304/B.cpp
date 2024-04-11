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

int n, m;
string a[4040] = {};
#include <queue>
#include <map>
map <string, bool> mp;
queue <string> q;

string mid = " ";

int main () {
    n = read(), m = read();
    int i, j;
    for (i = 1; i <= n; i++) cin >> a[i], mp[a[i]] = true;
    for (i = 1; i <= n; i++) {
        bool f = false;
        for (j = 0; j < m; j++) if (a[i][j] != a[i][m - j - 1]) f = true;
        if (!f) mid = a[i];
        else {
            string tmp; tmp.clear();
            for (j = m - 1; j >= 0; j--) tmp += a[i][j];
            if (mp[tmp]) q.push(a[i]), mp[a[i]] = false;
        }
    }
    string ans; ans.clear(); int len = 0;
    while (!q.empty()) ans += q.front(), len += m, q.pop();
    if (mid != " ") cout << len * 2 + m << endl; else cout << len * 2 << endl;
    cout << ans; if (mid != " ") cout << mid; for (i = len - 1; i >= 0; i--) cout << ans[i];
    return 0;
}