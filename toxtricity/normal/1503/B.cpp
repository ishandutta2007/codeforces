#include <bits/stdc++.h>

using pii = std::pair <int, int>;

const int N = 110;

int a[N][N];

int main(){
    std::vector <pii> vec1, vec2;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            if ((i + j) % 2 == 0){
                vec1.emplace_back(i, j);
            }
            else{
                vec2.emplace_back(i, j);
            }
        }
    }
    for (int i = 1; i <= n * n; ++ i){
        int col;
        scanf("%d", &col);
        if (col != 2 && !vec2.empty()){
            pii p = vec2.back();
            vec2.pop_back();
            a[p.first][p.second] = 2;
            printf("%d %d %d\n", 2, p.first, p.second);
        }
        else if (col != 1 && !vec1.empty()){
            pii p = vec1.back();
            vec1.pop_back();
            a[p.first][p.second] = 1;
            printf("%d %d %d\n", 1, p.first, p.second);
        }
        else{
            if (col == 1){
                pii p = vec1.back();
                vec1.pop_back();
                a[p.first][p.second] = 3;
                printf("%d %d %d\n", 3, p.first, p.second);
            }
            else{
                pii p = vec2.back();
                vec2.pop_back();
                a[p.first][p.second] = 3;
                printf("%d %d %d\n", 3, p.first, p.second);
            }
        }
        fflush(stdout);
    }
    return 0;
}