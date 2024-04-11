#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>

using namespace std;

int x[8][3];
long long u[8][3];

void check() {
    for (int i = 0; i < 8; i++) {
        // cerr << x[i][0] << " " << x[i][1] << " " << x[i][2] << endl;
        // exit(0);
        long long dd = 0, d2 = 0, d3 = 0;
        int cc = 0, c2 = 0, c3 = 0;
        for (int j = 0; j < 8; j++) {
            if (j == i) {
                continue;
            }
            long long cd = 0;
            for (int e = 0; e < 3; e++) {
                cd += (x[i][e] - x[j][e]) * 1LL * (x[i][e] - x[j][e]);
            }
            // cerr << cd << endl;
            if (cd >= dd) {
                if (cd > dd) {
                    d3 = d2;
                    c3 = c2;
                    d2 = dd;
                    c2 = cc;
                    cc = 0;
                }
                dd = cd;
                cc++;
            } else {
                if (cd >= d2) {
                    if (cd > d2) {
                        d3 = d2;
                        c3 = c2;
                        c2 = 0;
                    }
                    d2 = cd;
                    c2++;
                } else {
                    if (cd > d3) {
                        c3 = 0;
                    }
                    d3 = cd;
                    c3++;
                }
            }
        }
        // cerr << cc << " " << c2 << " " << c3 << endl;
        // exit(0);
        if ((cc != 1) || (c2 != 3) || (c3 != 3)) {
            return;
        }
        u[i][0] = dd;
        u[i][1] = d2;
        u[i][2] = d3;
    }
    // cerr << "found" << endl;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            if (u[i][j] != u[i + 1][j]) {
                return;
            }
        }
    }
    if (u[0][0] == 0) {
        return;
    }
    if (u[0][2] * 2 != u[0][1]) {
        return;
    }
    if (u[0][2] * 3 != u[0][0]) {
        return;
    }
    puts("YES");
    for (int i = 0; i < 8; i++) {
        printf("%d %d %d\n", x[i][0], x[i][1], x[i][2]);
    }
    exit(0);
}

void rec(int u) {
    if (u == 8) {
        check();
        return;
    }
    for (int i = 0; i < 6; i++) {
        rec(u + 1);
        next_permutation(x[u], x[u] + 3);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &x[i][j]);
        }
    }
    rec(0);
    puts("NO");
}