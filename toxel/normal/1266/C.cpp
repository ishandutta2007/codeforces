#include <bits/stdc++.h>

int main(){
    int r, c;
    scanf("%d%d", &r, &c);
    if (r == 1 && c == 1){
        puts("0");
        return 0;
    }
    if (c == 1){
        for (int i = 0; i < r; ++ i){
            printf("%d\n", i + 2);
        }
        return 0;
    }
    std::vector <int> vec1, vec2;
    for (int i = 2; i <= c + 1; ++ i){
        vec2.emplace_back(i);
    }
    vec1.emplace_back(1);
    for (int i = c + 2; i <= r + c; ++ i){
        vec1.emplace_back(i);
    }
    for (int i = 0; i < r; ++ i){
        for (int j = 0; j < c; ++ j){
            printf("%d%c", vec1[i] * vec2[j], " \n"[j == c - 1]);
        }
    }
    return 0;
}