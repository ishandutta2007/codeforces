#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define pii pair <LL, LL>

using namespace std;

const int N = 200100;
const ULL M = 1LL << 33;
const double eps = 1e-8;

set <int> st[2];
//set <int> :: iterator it;
vector <int> g[N], p[5];
queue <int> f[2];
int c[2];
char s[N];

void w (int x) {
//    cout <<x << ' ' << s[g[x][0]] << ' ' << s[g[x][g[x].size() - 1]] << endl;
    for (int i = 0; i < g[x].size(); i++) printf ("%d ", g[x][i] + 1);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    scanf ("%s", s);
    int n = strlen (s), r = 0, m = 0;
    c[0] = c[1] = 0;
//    int c1 = 0, c2 = 0;
//    for (int i = 0; i < n; i++) {
//        if (s[i] == 'L') c1++; else c2++;
//        if (s[i] == 'L') st[0].insert (i);
//        else st[1].insert (i);
//    }
    for (int i = 0; i < n; i++) {
        int now = s[i] == 'L' ? 0 : 1;
        if (!f[now ^ 1].empty()) {
            int u = f[now ^ 1].front();
            f[now ^ 1].pop();
            g[u].push_back (i);
            f[now].push(u);
        } else {
            m++;
            g[m].push_back (i);
            f[now].push(m);
        }
    }
//    int c1 = 0, c2 = 0;
    for (int i = 1; i <= m; i++) {
//        w (i);
         if (s[g[i][0]] == 'L' && s[g[i][g[i].size() - 1]] == 'L') p[0].push_back (i);
         if (s[g[i][0]] == 'R' && s[g[i][g[i].size() - 1]] == 'R') p[1].push_back (i);
         if (s[g[i][0]] == 'L' && s[g[i][g[i].size() - 1]] == 'R') p[2].push_back (i);
         if (s[g[i][0]] == 'R' && s[g[i][g[i].size() - 1]] == 'L') p[3].push_back (i);
    }
    if (p[0].size() < p[1].size()) {
        swap (p[0], p[1]);
        swap (p[2], p[3]);
    }
    cout << m - 1 <<endl;
    for (int i = 0; i < p[2].size(); i++) w (p[2][i]);
    if (p[0].size()) w (p[0][0]);
    for (int i = 0; i < p[3].size(); i++) w (p[3][i]);
    int now = 1, pos = 0;
    while (p[now].size() > pos) {
        w (p[now][pos]);
        if (now == 0) now = 1;
        else now = 0, pos++;
    }
}