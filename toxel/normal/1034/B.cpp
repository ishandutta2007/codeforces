#include<bits/stdc++.h>

typedef long long ll;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    if (n > m){
        std::swap(n, m);
    }
    int ans;
    if (n == 1){
        ans = m % 6;
        if (ans == 4){
            ans = 2;
        }
        else if (ans == 5){
            ans = 1;
        }
    }
    else if (n == 2){
        ans = m == 2 ? 4 : m == 3 || m == 7 ? 2 : 0;
    }
    else{
        ans = 1ll * n * m & 1;
    }
    printf("%lld\n", 1ll * n * m - ans);
    return 0;
}