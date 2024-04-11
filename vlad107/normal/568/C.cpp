#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <memory.h>

using namespace std;

const int N = 444;

bool g[N][2][N][2];
string vv, s, ans, p;
int a[N], n, m, b[N], L;

void solve(int l) {
    // cerr << l << " " << p << endl;
    for (int i = 0; i < n; i++) b[i] = -1;
    for (int i = 0; i <= min(l, n - 1); i++) b[i] = a[p[i] - 'a'];
    for (int i = 0; i < n; i++) {
        if (i > l) {
            if (b[i] == -1) {
                b[i] = a[0];
            }
            int x = 0;
            while ((x < L) && (a[x] != b[i])) ++x;
            if (x == L) {
                // cerr << "oo" << endl;
                return;
            }
            p[i] = 'a' + x;
        }
        int x = b[i];
        // cerr << i << " -- " << x << endl;
        for (int j = 0; j < n; j++) {
            for (int y = 0; y < 2; y++) {
                if (g[i][x][j][y]) {
                    if ((b[j] != -1) && (b[j] != y)) {
                        // cerr << "oo" << endl;
                        return;
                    }
                    b[j] = y;
                }
            }
        }
    }
    if ((ans == "") || (p < ans)) {
        ans = p;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> vv;
    L = vv.size();
    for (int i = 0; i < L; i++) {
        a[i] = vv[i] == 'V';
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        char cu, cv;
        cin >> x >> cu >> y >> cv;
        --x; --y;
        int u = cu == 'V';
        int v = cv == 'V';
        g[x][u][y][v] = 1;
        g[y][1-v][x][1-u] = 1;
    }
    for (int k = 0; k < n; k++) {
        for (int z = 0; z < 2; z++) {
            for (int i = 0; i < n; i++) {
                for (int x = 0; x < 2; x++) {
                    for (int j = 0; j < n; j++) {
                        for (int y = 0; y < 2; y++) {
                            if ((g[i][x][k][z]) && (g[k][z][j][y])) {
                                g[i][x][j][y] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    cin >> s;
    ans = "";
    for (int i = n; i >= 0; i--) {
        if (i == n) {
            p = s;
            solve(i);
            continue;
        }
        bool used[2];
        used[0] = used[1] = 0;
        for (char c = s[i] + 1; c < 'a' + L; c++) {
            if (!used[a[c - 'a']]) {
                p = s;
                p[i] = c;
                solve(i);
                used[a[c - 'a']] = 1;
            }
        }
    }
    // return 0;
    if (ans == "") {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}