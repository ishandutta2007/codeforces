#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define getm int m = (l + r) >> 1
#define LL long long
#define ULL unsigned long long
#define pii pair <LL, LL>

using namespace std;

const int N = 100100;
char c[20];
int res[20], ans, t[10], tmp[20], cnt[20], ned[20][10];

int jug (int x, int num) {
    for (int i = 1; i <= 4; i++) if (cnt[i] < num * ned[x][i]) return 0;
    return 1;
}

void remove (int x, int num) {
    for (int i = 1; i <= 4; i++) cnt[i] -= num * ned[x][i];
}

void resume (int x, int num) {
    for (int i = 1; i <= 4; i++) cnt[i] += num * ned[x][i];
}

void dfs (int x, int len) {
//    cout << x << ' ' << len << endl;
    if (x == 10) {
        for (int i = 1; i <= 4; i++) if (cnt[i]) return;
        if (len > ans) {
            ans = len;
            for (int i = 2; i <= 9; i++) res[i] = tmp[i];
        }
        return;
    }
    int i = 0;
    while (jug (x, i)) {
        remove (x, i);
        tmp[x] = i;
        dfs (x + 1, len + i);
        resume (x, i);
        i++;
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    t[1] = 2;
    t[2] = 3;
    t[3] = 5;
    t[4] = 7;
    for (int i = 2; i <= 9; i++) {
        int k = i;
        for (int j = 1; j <= 4; j++) {
            ned[i][j] = ned[i - 1][j];
            while (k % t[j] == 0) { k /= t[j]; ned[i][j]++; }
//            cout << ned[i][j] << ' ';
        }
//        cout << endl;
    }
    int c;
    for (int i = 1; i <= n; i++) {
        scanf ("%1d", &c);
//        cout << c << endl;
        if (c < 2) continue;
        for (int j = 1; j <= 4; j++) {
            cnt[j] += ned[c][j];
        }
    }
//    for (int i = 1; i <= 4; i++) cout << cnt[i] << ' ';
    dfs (2, 0);
    for (int i = 9; i >= 2; i--) {
        for (int j = 1; j <= res[i]; j++) {
            cout << i;
        }
    }
}