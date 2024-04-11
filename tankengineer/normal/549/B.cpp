#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 105;

int n;

bool inv[N];

int cnt[N], bar[N];

char map[N][N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &bar[i]);
        cnt[i] = 0;
        inv[i] = false;
    }
    int ccnt = 0;
    while (true) {
        int flip = -1;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == bar[i]) {
                flip = i; 
                break;
            }
        }
        if (flip == -1) {
            break;
        }
        if (inv[flip] == true) {
            printf("-1\n");
            return 0;
        }
        inv[flip] = true;
        for (int i = 0; i < n; ++i) {
            if (map[flip][i] == '1') {
                ++cnt[i];
            }
        }
        ++ccnt;
    }
    printf("%d\n", ccnt);
    for (int i = 0; i < n; ++i) {
        if (inv[i]) {
            printf("%d%c", i + 1, (--ccnt) == 0 ? '\n' : ' ');
        }
    }

    return 0;
}