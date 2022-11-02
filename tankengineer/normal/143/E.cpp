#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int pattern[4][5][2] = {
{{0, 0}, {0, 1}, {0, 2}, {1, 1}, {2, 1}},
{{0, 0}, {1, -2}, {1, -1}, {1, 0}, {2, 0}},
{{0, 0}, {1, 0}, {2, -1}, {2, 0}, {2, 1}},
{{0, 0}, {1, 0}, {1, 1}, {1, 2}, {2, 0}}};

int n, m;

int ans, cnt, cc[10];

int map[10][10], rec[10][10];

void solve(int i, int j) {
    if (j == m) {
        ++i, j = 0;
        if (cnt + cc[n - i] <= ans) {
            return;
        }
    }
    if (i == n) {
        if (cnt > ans) {
            //cout << ans << endl;
            ans = cnt;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    rec[i][j] = map[i][j];
                }
            }
        }
        return;
    }
    for (int k = 0; k < 4; ++k) {
        bool check = true;
        for (int l = 0; l < 5; ++l) {
            int x = i + pattern[k][l][0],
                y = j + pattern[k][l][1];
            if (!(x >= 0 && x < n && y >= 0 && y < m && map[x][y] == 0)) {
                check = false;
                break;
            }
        }
        if (check) {
            ++cnt;
            for (int l = 0; l < 5; ++l) {
                map[i + pattern[k][l][0]][j + pattern[k][l][1]] = cnt;
            }
            solve(i, j + 1);
            --cnt;
            for (int l = 0; l < 5; ++l) {
                map[i + pattern[k][l][0]][j + pattern[k][l][1]] = 0;
            }           
        }
    }
    solve(i, j + 1);
}

int main() {
    int nn, mm;
    scanf("%d%d", &nn, &mm);
    for (int i = 1; i <= nn; ++i) {
        n = i, m = mm;
        //ans = 0;
        solve(0, 0);
        cc[i] = ans;
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%c", rec[i][j] ? 'A' + rec[i][j] - 1 : '.');
        }
        printf("\n");
    }
    return 0;
}