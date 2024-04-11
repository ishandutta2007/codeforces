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

const int N = 1111;

int n, m, eq[N];
char a[N][N];

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) a[i][j] = getchar();
        scanf("\n");
    }
    for (int i = 0; i + 1 < n; i++) eq[i] = true;
    int ans = 0;
    for (int j = 0; j < m; j++) {
        bool flag = false;
        for (int i = 0; i + 1 < n; i++) {
            if ((eq[i]) && (a[i][j] > a[i + 1][j])) {
                flag = true;
                break;
            }
        }
        if (flag) {
            ans++;
        } else {
            for (int i = 0; i + 1 < n; i++) {
                eq[i] &= (a[i][j] == a[i + 1][j]);
            }
        }
    }
    printf("%d\n", ans);
}