#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <memory.h>
#include <cassert>
#include <set>
#include <map>
#include <vector>
#include <ctime>

#define N 1111

using namespace std;

int s0, s1, n, m, kg[N], a[N][N], t, nom, l[N], r[N];

int main() {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &kg[i]);
        for (int j = 0; j < kg[i]; j++)
            scanf("%d", &a[i][j]);
        m += kg[i];
    }
    for (int i = 0; i < n; i++) {
        l[i] = 0;
        r[i] = kg[i] - 1;
    }
    s0 = 0;
    s1 = 0;
    t = 1;
    for (int i = 0; i < m; i++) {
        t ^= 1;
        int maxt = -1000000000;
        for (int j = 0; j < n; j++) {
            if (l[j] > r[j])
                continue;
            int ll = l[j], rr = r[j];
            int st = 0;
            if ((r[j] - l[j] + 1) % 2 == 1)
                st = (a[j][(l[j] + r[j]) / 2]);
/*          if (t == 0) {
                int el = ll, er = rr;
                while (el <= er) {
                    st += a[j][el];
                    if (er > el)
                        st -= a[j][er];
                    el++;
                    er--;
                }
            } else {
                int el = ll, er = rr;
                while (el <= er) {
                    st += a[j][er];
                    if (el < er)
                        st -= a[j][el];
                    el++;
                    er--;
                }
            }    */
            if (st > maxt) {
                maxt = st;
                nom = j;
            }
        }
        if (t == 0) {
            s0 += a[nom][l[nom]];
            l[nom]++;
        } else {
            s1 += a[nom][r[nom]];
            r[nom]--;
        }
    }
    cout << s0 << " " << s1 << endl;
}