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
#define psi pair <string, int>
using namespace std;

bool cmp (psi a, psi b) {
    if (a.yy != b.yy) return a.yy > b.yy;
    return a.xx < b.xx;
}

vector <psi> g[11001];

int main () {
//    freopen ("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int a, b, x, y;
    string s;
    int n, m;
    cin >>n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s >> x >>y;
        g[x].push_back (psi (s, y));
    }
    for (int i = 1; i <= m; i++) {
        sort (g[i].begin(), g[i].end(), cmp);
        if (g[i].size() > 2 && (g[i][1].yy == g[i][2].yy)) cout << "?\n";
        else cout << g[i][0].xx <<' ' << g[i][1].xx << endl;
    }
}