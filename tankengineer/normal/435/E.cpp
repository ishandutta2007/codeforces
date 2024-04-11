#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;

const int N = 1005;
char map[N][N], t[N][N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
    }
    char c[4];
    for (int i = 0; i < 4; ++i) {
        c[i] = i + 1 + '0';
    }
    do {
        bool go = true;
        for (int j = 0; j < m; ++j) {
            char p[2];
            if (j % 2 == 0) {
                p[0] = c[0], p[1] = c[1];
            } else {
                p[0] = c[2], p[1] = c[3];
            }
            bool succ = false;
            for (int _ = 0; _ < 2; ++_) {
                bool flag = true;
                for (int i = 0; i < n; ++i) {
                    if (map[i][j] != '0' && map[i][j] != p[i % 2]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    swap(p[0], p[1]);
                } else {
                    succ = true;
                    break;
                }
            }
            if (succ) {
                for (int i = 0; i < n; ++i) {
                    t[i][j] = p[i % 2];
                }
            } else {
                go = false;
                break;
            }
        }
        if (go) {
            for (int i = 0; i < n; ++i) {
                printf("%s\n", t[i]);
            }
            return 0;
        }
    } while (next_permutation(c, c + 4));
    for (int i = 0; i < 4; ++i) {
        c[i] = i + 1 + '0';
    }
    do {
        bool go = true;
        for (int i = 0; i < n; ++i) {
            char p[2];
            if (i % 2 == 0) {
                p[0] = c[0], p[1] = c[1];
            } else {
                p[0] = c[2], p[1] = c[3];
            }
            bool succ = false;
            for (int _ = 0; _ < 2; ++_) {
                bool flag = true;
                for (int j = 0; j < m; ++j) {
                    if (map[i][j] != '0' && map[i][j] != p[j % 2]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    swap(p[0], p[1]);
                } else {
                    succ = true;
                    break;
                }
            }
            if (succ) {
                for (int j = 0; j < m; ++j) {
                    t[i][j] = p[j % 2];
                }
            } else {
                go = false;
                break;
            }
        }
        if (go) {
            for (int i = 0; i < n; ++i) {
                printf("%s\n", t[i]);
            }
            return 0;
        }
    } while (next_permutation(c, c + 4));
    printf("0\n");
    return 0;
}