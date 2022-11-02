#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

struct Tree {
    int l, r, mx;
};


Tree tr[4 * N];
int nxt[N];
vector<pair<int, int>> g[N];
int n, k;

void build(int x, int l, int r) {
    tr[x].l = l;
    tr[x].r = r;
    tr[x].mx = -1;
    if (l < r) {
        int mid = (l + r) / 2;
        build(x + x + 1, l, mid);
        build(x + x + 2, mid + 1, r);
    }                              
}

int getmax(int x, int l, int r) {
    if ((tr[x].l == l) && (tr[x].r == r)) {
        return tr[x].mx;
    }
    int res = -1;
    if (l <= tr[x + x + 1].r) res = max(res, getmax(x + x + 1, l, min(r, tr[x + x + 1].r)));
    if (r >= tr[x + x + 2].l) res = max(res, getmax(x + x + 2, max(l, tr[x + x + 2].l), r));
    return res;
}

void modif(int x, int it, int val) {
    if ((tr[x].l == it) && (tr[x].r == it)) {
        tr[x].mx = val;
        return;
    }
    if (it <= tr[x + x + 1].r) modif(x + x + 1, it, val);
    if (it >= tr[x + x + 2].l) modif(x + x + 2, it, val);
    tr[x].mx = max(tr[x + x + 1].mx, tr[x + x + 2].mx);
}

void dfs(int l, int r) {
    if (l > r) return;
    int x = l;
    for (int i = 0; i < g[x].size(); i++) {
        if (g[x][i].second) {
            if ((g[x][i].first <= nxt[x]) || (g[x][i].first > r)) {
                puts("IMPOSSIBLE");
                exit(0);
            }
        } 
    }
    dfs(l + 1, nxt[l]);
    dfs(nxt[l] + 1, r);
}

void print(int l, int r) {
    if (l > r) return;
    print(l + 1, nxt[l]);
    printf("%d ", l + 1);
    print(nxt[l] + 1, r);
}

int main() {
//  freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        string c;
        scanf("%d %d", &x, &y);
        cin >> c;
        --x; --y;
        if (y <= x) {
            puts("IMPOSSIBLE");
            return 0;
        }
        g[x].push_back(make_pair(y, c != "LEFT"));
    }
    build(0, 0, n - 1);
    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = i;
        for (int j = 0; j < g[i].size(); j++) {
            if (!g[i][j].second) {
                nxt[i] = max(nxt[i], g[i][j].first);
            }
        }
        nxt[i] = max(i, getmax(0, i, nxt[i]));
        while (1) {
            int cur = getmax(0, i, nxt[i]);
            if (cur <= nxt[i]) break;
            nxt[i] = cur;
        }
        int gt = i;
        for (int j = 0; j < g[i].size(); j++) {
            gt = max(gt, g[i][j].first);
        }
//      gt = i;
        modif(0, i, max(nxt[i], gt));
    }
    dfs(0, n - 1);
    print(0, n - 1);
}