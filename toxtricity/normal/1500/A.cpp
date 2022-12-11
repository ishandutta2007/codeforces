#include <bits/stdc++.h>

const int N = 5000010;
using pii = std::pair <int, int>;

int a[N];
std::vector <int> pos[N];
pii pos1[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++ i){
        pos[a[i]].emplace_back(i + 1);
    }
    int p1 = -1, p2 = -1;
    for (int i = 0; i < N; ++ i){
        if (int(pos[i].size()) >= 4){
            puts("YES");
            for (int j = 0; j < 4; ++ j){
                printf("%d%c", pos[i][j], " \n"[j == 3]);
            }
            return 0;
        }
        if (int(pos[i].size()) >= 2){
            if (p1 == -1){
                p1 = i;
            }
            else{
                p2 = i;
            }
        }
    }
    if (p2 != -1){
        puts("YES");
        printf("%d %d %d %d\n", pos[p1][0], pos[p2][0], pos[p1][1], pos[p2][1]);
        return 0;
    }
    for (int i = 0; i < N; ++ i){
        pos1[i] = {-1, -1};
    }
    if (p1 != -1){
        pos1[2 * p1] = {pos[p1][0], pos[p1][1]};
    }
    int ban1 = p1 != -1 ? pos[p1][1] - 1 : -1, ban2 = p1 != -1 && int(pos[p1].size()) == 3 ? pos[p1][2] - 1 : -1;
    for (int i = 0; i < n; ++ i){
        if (i == ban1 || i == ban2){
            continue;
        }
        for (int j = i + 1; j < n; ++ j){
            if (j == ban1 || j == ban2){
                continue;
            }
            int pp = a[i] + a[j];
            auto &vec = pos1[pp];
            if (vec.first == -1){
                vec = {i + 1, j + 1};
                continue;
            }
            puts("YES");
            printf("%d %d %d %d\n", vec.first, vec.second, i + 1, j + 1);
            return 0;
        }
    }
    puts("NO");
    return 0;
}