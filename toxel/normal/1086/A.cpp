#include<bits/stdc++.h>

typedef std::pair <int, int> pii;

int main(){
    pii p1[3], p2[3];
    for (int i = 0, x, y; i < 3; ++ i){
        scanf("%d%d", &x, &y);
        p1[i] = {x, y};
        p2[i] = {y, x};
    }
    std::sort(p1, p1 + 3);
    std::sort(p2, p2 + 3);
    printf("%d\n", p1[2].first - p1[0].first + p2[2].first - p2[0].first + 1);
    if (p1[0].first == p1[1].first || p1[1].first == p1[2].first){
        for (int i = p1[0].first; i <= p1[2].first; ++ i){
            printf("%d %d\n", i, p2[1].first);
        }
        for (int i = 0; i < 3; ++ i){
            for (int j = p1[i].second; j < p2[1].first; ++ j){
                printf("%d %d\n", p1[i].first, j);
            }
            for (int j = p1[i].second; j > p2[1].first; -- j){
                printf("%d %d\n", p1[i].first, j);
            }
        }
    }
    else{
        for (int i = p2[0].first; i <= p2[2].first; ++ i){
            printf("%d %d\n", p1[1].first, i);
        }
        for (int i = 0; i < 3; ++ i){
            for (int j = p2[i].second; j < p1[1].first; ++ j){
                printf("%d %d\n", j, p2[i].first);
            }
            for (int j = p2[i].second; j > p1[1].first; -- j){
                printf("%d %d\n", j, p2[i].first);
            }
        }
    }
    return 0;
}