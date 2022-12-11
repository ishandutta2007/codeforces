#include<bits/stdc++.h>

const int N = 110;

int a[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int max = 0;
    std::multiset <int> set;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        max = std::max(max, a[i]);
        set.insert(a[i]);
    }
    for (int i = 0; i < m; ++ i){
        auto u = set.begin();
        set.erase(u);
        set.insert(*u + 1);
    }
    printf("%d %d\n", *(-- set.end()), max + m);
    return 0;
}