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

const int N = 77;
const int K = 2;

pair<int, int> pred[N][K][K];
int f[N][K][K];
long long ff[N][K][K];
long long l, r, pw2[N];
int tt, a[N], b[N];

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d", &tt);
    pw2[0] = 1;
    for (int i = 1; i < 64; i++) pw2[i] = 2 * pw2[i - 1];
    while (tt--) {
        cin >> l >> r;
        for (int i = 63; i >= 0; i--) {
            a[i] = l % 2;
            b[i] = r % 2;
            l /= 2;
            r /= 2;
        }
        for (int i = 0; i <= 64; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) f[i][j][k] = -1;
            }
        }
        f[0][0][0] = 0;
        ff[0][0][0] = 0;
        for (int i = 0; i < 64; i++) {
            for (int f0 = 0; f0 < 2; f0++) {
                for (int f1 = 0; f1 < 2; f1++) {
                    if (f[i][f0][f1] == -1) continue;
                    for (int x = 0; x < 2; x++) {
                        int nf0 = f0;
                        int nf1 = f1;
                        if ((nf0 == 0) && (x < a[i])) continue;
                        if ((nf1 == 0) && (x > b[i])) continue;
                        if (x > a[i]) nf0 = 1;
                        if (x < b[i]) nf1 = 1;
                        int cur = f[i][f0][f1] + x;
                        long long cur2 = ff[i][f0][f1];
                        if (x == 1) cur2 += pw2[63 - i];
                        if ((cur > f[i + 1][nf0][nf1]) || ((cur == f[i + 1][nf0][nf1]) && (cur2 < ff[i + 1][nf0][nf1]))) {
                            f[i + 1][nf0][nf1] = cur;                                 
                            ff[i + 1][nf0][nf1] = cur2;
                            pred[i + 1][nf0][nf1] = make_pair(f0, f1);
                        }
                    }
                }
            }
        }
        int mx = -1, f0, f1;
        long long cur = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (f[64][i][j] == -1) continue;
                if ((f[64][i][j] > mx) || ((f[64][i][j] == mx) && (ff[64][i][j] < cur))) {
                    mx = f[64][i][j];
                    cur = ff[64][i][j];
                    f0 = i;
                    f1 = j;
                }
            }
        }
        cout << cur << endl;
    }
}