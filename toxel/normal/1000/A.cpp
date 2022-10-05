#include<bits/stdc++.h>

const int N = 10;
const int M = 110;

char s[N];

int main(){
    int n;
    scanf("%d", &n);
    std::map <std::string, int> Hash1, Hash2;
    for (int i = 0; i < n; ++ i){
        scanf("%s", s);
        ++ Hash1[s];
    }
    for (int i = 0; i < n; ++ i){
        scanf("%s", s);
        ++ Hash2[s];
    }
    int ans = 0;
    for (auto u : Hash2){
        ans += std::min(u.second, Hash1[u.first]);
    }
    printf("%d\n", n - ans);
    return 0;
}