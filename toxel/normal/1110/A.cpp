#include<bits/stdc++.h>

const int N = 100010;

int a[N];

int main(){
    int b, k;
    scanf("%d%d", &b, &k);
    for (int i = 0; i < k; ++ i){
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int i = 0; i < k; ++ i){
        ans = (ans * b + a[i]) % 2;
    }
    puts(ans ? "odd" : "even");
    return 0;
}