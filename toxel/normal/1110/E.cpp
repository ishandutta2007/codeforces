#include<bits/stdc++.h>

const int N = 100010;

int c[N], t[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &t[i]);
    }
    if (c[0] != t[0] || c[n - 1] != t[n - 1]){
        puts("No");
        return 0;
    }
    for (int i = n - 1; i >= 1; -- i){
        c[i] -= c[i - 1];
        t[i] -= t[i - 1];
    }
    std::sort(c + 1, c + n);
    std::sort(t + 1, t + n);
    for (int i = 1; i < n; ++ i){
        if (c[i] != t[i]){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}