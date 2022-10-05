#include<bits/stdc++.h>

const int N = 1010;

char s[N][N];
int n;

bool check(int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= n) return false;
    return s[x][y] == 'X';
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            cnt += check(i, j) && check(i - 1, j - 1) && check(i - 1, j + 1) && check(i + 1, j - 1) && check(i + 1, j + 1);
        }
    }
    printf("%d\n", cnt);
    return 0;
}