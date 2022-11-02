#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m, q;

const int N = 1005;
int map[N][N], dir[N][N][4];

const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int cal(int x, int y, int d) {
    int cnt = 0;
    while (x >= 0 && x < n && y >= 0 && y < m && map[x][y] == 1) {
        ++cnt;
        x += dx[d], y += dy[d];
    }
    return cnt;
}

int l[N], r[N];

int solve(vector<int> h, int pos) {
    int n = h.size();
/*
for (int i = 0; i < n; ++i) {
    printf("%d ", h[i]);
}
printf("\n");
*/
    vector<int> stack;
    for (int i = 0; i < n; ++i) {
        while (stack.size() && h[stack.back()] > h[i]) {
            stack.pop_back();
        }
        if (stack.size()) {
            l[i] = stack.back();
        } else {
            l[i] = -1;
        }
        stack.push_back(i);
    }
    stack.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (stack.size() && h[stack.back()] >= h[i]) {
            stack.pop_back();
        }
        if (stack.size()) {
            r[i] = stack.back() - 1;
        } else {
            r[i] = n - 1;
        }
        stack.push_back(i);
    }
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if (pos > l[i] && pos <= r[i]) {
            ret = max(ret, h[i] * (r[i] - l[i]));
        }
    }
    return ret;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dir[i][j][1] = map[i][j] * ((j ? dir[i][j - 1][1] : 0) + 1);
            dir[i][j][3] = map[i][j] * ((i ? dir[i - 1][j][3] : 0) + 1);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            dir[i][j][0] = map[i][j] * ((j + 1 < m ? dir[i][j + 1][0] : 0) + 1);
            dir[i][j][2] = map[i][j] * ((i + 1 < n ? dir[i + 1][j][2] : 0) + 1);
        }
    }
    while (q--) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        --x, --y;
        if (op == 1) {
            map[x][y] ^= 1;
            for (int d = 0; d < 4; ++d) {
                dir[x][y][d] = cal(x, y, d);
            }
            for (int i = x - 1; i >= 0; --i) {
                if (map[i][y] == 0) {
                    break;
                }
                dir[i][y][2] = dir[i + 1][y][2] + 1;
            }
            for (int i = x + 1; i < n; ++i) {
                if (map[i][y] == 0) {
                    break;
                }
                dir[i][y][3] = dir[i - 1][y][3] + 1;
            }
            for (int j = y - 1; j >= 0; --j) {
                if (map[x][j] == 0) {
                    break;
                }
                dir[x][j][0] = dir[x][j + 1][0] + 1;
            }
            for (int j = y + 1; j < m; ++j) {
                if (map[x][j] == 0) {
                    break;
                }
                dir[x][j][1] = dir[x][j - 1][1] + 1;
            }
        } else {
            if (map[x][y] == 0) {
                printf("0\n");
                continue;
            }
            int left = y - dir[x][y][1] + 1, right = y + dir[x][y][0],
                up = x - dir[x][y][3] + 1, down = x + dir[x][y][2];
            int ans = 1;
            vector<int> tmp;
            for (int j = left; j < right; ++j) {
                tmp.push_back(dir[x][j][3]);
            }
            ans = max(ans, solve(tmp, y - left));
            tmp.clear();
            for (int j = left; j < right; ++j) {
                tmp.push_back(dir[x][j][2]);
            }
            ans = max(ans, solve(tmp, y - left));
            tmp.clear();
            for (int j = up; j < down; ++j) {
                tmp.push_back(dir[j][y][0]);
            }
            ans = max(ans, solve(tmp, x - up));
            tmp.clear();
            for (int j = up; j < down; ++j) {
                tmp.push_back(dir[j][y][1]);
            }
            ans = max(ans, solve(tmp, x - up));
            printf("%d\n", ans);
            continue;
        }
/*
for (int i = 0; i < 4; ++i) {
    cout << "DIR" << ' ' << i << endl;
    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < m; ++k) {
            printf("%d", dir[j][k][i]);
        }
        printf("\n");
    }
    printf("\n");
}
*/
    }
    return 0;
}