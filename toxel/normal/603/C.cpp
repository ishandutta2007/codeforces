#include<bits/stdc++.h>

const int N = 100010;

int a[N];

int sg(int x){
    if (x <= 3){
        return x & 1;
    }
    if (x & 1){
        return 0;
    }
    std::set <int> set;
    set.insert(sg(x >> 1));
    set.insert(sg(x - 1));
    for (int i = 0; ; ++ i){
        if (!set.count(i)){
            return i;
        }
    }
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    if (!(k & 1)){
        int ans = 0;
        for (int i = 0; i < n; ++ i){
            ans ^= a[i] <= 2 ? a[i] : (a[i] & 1) ^ 1;
        }
        puts(ans ? "Kevin" : "Nicky");
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        ans ^= sg(a[i]);
    }
    puts(ans ? "Kevin" : "Nicky");
    return 0;
}