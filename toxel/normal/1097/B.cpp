#include<bits/stdc++.h>

int main(){
    int n;
    scanf("%d", &n);
    std::set <int> set = {0};
    for (int i = 0; i < n; ++ i){
        int x;
        scanf("%d", &x);
        std::set <int> tmp;
        for (auto u : set){
            tmp.insert((x + u) % 360);
            tmp.insert((x - u + 360) % 360);
        }
        set = tmp;
    }
    puts(set.count(0) ? "YES" : "NO");
    return 0;
}