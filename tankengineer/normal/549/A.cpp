#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 55;

int n, m;

char map[N][N];

bool check(int i, int j) {
    char face[4] = {map[i][j], map[i + 1][j], map[i][j + 1], map[i + 1][j + 1]};
    sort(face, face + 4);
    do {
        if (face[0] == 'f' && face[1] == 'a' && face[2] == 'c' && face[3] == 'e') {
          return true;
        }  
    } while (next_permutation(face, face + 4));
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
    } 
    int ans = 0;
    for (int i = 0; i + 2 <= n; ++i) {
        for (int j = 0; j + 2 <= m; ++j) {
            if (check(i, j)) {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}