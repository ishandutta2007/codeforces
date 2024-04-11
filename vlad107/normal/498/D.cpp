#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <assert.h>

using namespace std;

const int N = 100500;
const int K = 4 * N;
const int T = 60;

pair<short, int> nxt[K][T];
pair<short, int> go[T][7];
int tl[K], tr[K], rev[N], a[N], n;
pair<short, int> ans;

void upd(int x) {
    for (int i = 0; i < 60; i++) {
        nxt[x][i] = make_pair(nxt[x + x + 2][nxt[x + x + 1][i].first].first,
                        nxt[x + x + 1][i].second + nxt[x + x + 2][nxt[x + x + 1][i].first].second);
    }
}

void build(int x, int l, int r) {
    tl[x] = l; tr[x] = r;
    if (l < r) {
        int mid = (l + r) >> 1;
        build(x + x + 1, l, mid);
        build(x + x + 2, mid + 1, r);
        upd(x);
    } else {
        for (int i = 0; i < 60; i++) {
            nxt[x][i] = go[i][a[l]];
        }
        rev[l] = x;
    }
}

void solve(int x, int l, int r) {
    if ((tl[x] == l) && (tr[x] == r)) {
        ans = make_pair(nxt[x][ans.first].first, ans.second + nxt[x][ans.first].second);
        return;
    }
    if (l <= tr[x + x + 1]) solve(x + x + 1, l, min(r, tr[x + x + 1]));
    if (r >= tl[x + x + 2]) solve(x + x + 2, max(l, tl[x + x + 2]), r);
}

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < 60; i++) {
        for (int j = 2; j <= 6; j++) {
            if (i % j != 0) {
                go[i][j] = make_pair((i + 1) % 60, 1);
            } else {
                go[i][j] = make_pair((i + 2) % 60, 2);
            }
        }
    }
    build(0, 0, n - 1);
    int tt;
    scanf("%d\n", &tt);
    while (tt--) {
        char c;
        int x, y;
        scanf("%c %d %d\n", &c, &x, &y);
        if (c == 'A') {
            --x;
            --y;
            --y;
            ans.first = 0;
            ans.second = 0;
            solve(0, x, y);
            printf("%d\n", ans.second);
        } else {
            --x;
            a[x] = y;
            x = rev[x];
            for (int i = 0; i < 60; i++) nxt[x][i] = go[i][y];
            while (x > 0) {
                x = (x - 1) >> 1;
                upd(x);
            }
        }
    }
}