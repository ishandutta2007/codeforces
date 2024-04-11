#include<bits/stdc++.h>

const int N = 5010;

int t[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &t[i]);
    }
    std::sort(t, t + n);
    n = std::unique(t, t + n) - t;
    for (int i = 0; i < n - 2; ++ i){
        if (t[i] == t[i + 1] - 1 && t[i + 1] == t[i + 2] - 1){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}