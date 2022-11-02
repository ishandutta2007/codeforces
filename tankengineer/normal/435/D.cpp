#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;

const int N = 1005;
char map[N][N];

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int len[N][N][8];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
    }
    for (int d = 0; d < 8; ++d) {
        int si, ei, di;
        if (dx[d] == 1) {
            si = n - 1, ei = -1, di = -1;
        } else {
            si = 0, ei = n, di = 1;
        }
        int sj, ej, dj;
        if (dy[d] == 1) {
            sj = m - 1, ej = -1; dj = -1;
        } else {
            sj = 0; ej = m, dj = 1;
        }
        for (int i = si; i != ei; i += di) {
            for (int j = sj; j != ej; j += dj) {
                int ti = i + dx[d], tj = j + dy[d];
                if (ti >= 0 && ti < n && tj >= 0 && tj < m) {
                    len[i][j][d] = (map[i][j] == '0') * (len[ti][tj][d] + (map[i][j] == '0'));
                } else {
                    len[i][j][d] = map[i][j] == '0';
                }
//cout << i << ' ' << j << ' ' << d << ' ' << len[i][j][d] << endl;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int d = 0; d < 8; ++d) {
                int d1 = (d + 2) % 8;
                for (int l = 1; l < len[i][j][d] && l < len[i][j][d1]; ++l) {
                    int ti = i + dx[d] * l, tj = j + dy[d] * l, d2 = (d + 3) % 8, tti = i + dx[d1] * l, ttj = j + dy[d1] * l;
                    if (d2 % 2 == 0 && len[ti][tj][d2] >= 2 * l + 1) {
                        ++ans;
                    } else if (d2 % 2 == 1 && len[ti][tj][d2] >= l + 1) {
                        ++ans;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}