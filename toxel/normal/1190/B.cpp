#include <bits/stdc++.h>

typedef long long ll;
const int N = 100010;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    std::map <int, int> map;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        ++ map[a[i]];
    }
    if (n == 1){
        puts(a[0] & 1 ? "sjfnb" : "cslnb");
        return 0;
    }
    ll sum = 0;
    for (auto u : map){
        sum += u . second - 1;
    }
    if (sum >= 2){
        puts("cslnb");
        return 0;
    }
    std::sort(a, a + n);
    if (sum == 0){
        ll tot = 0;
        for (int i = 0; i < n; ++ i){
            tot += a[i] - i;
        }
        if (tot & 1){
            puts("sjfnb");
        }
        else{
            puts("cslnb");
        }
        return 0;
    }
    for (int i = 0; i < n - 1; ++ i){
        if (a[i] == a[i + 1]){
            if (a[i] == 0){
                puts("cslnb");
                return 0;
            }
            else{
                -- a[i];
                break;
            }
        }
    }
    for (int i = 0; i < n - 1; ++ i){
        if (a[i] == a[i + 1]){
            puts("cslnb");
            return 0;
        }
    }
    ll tot = 0;
    for (int i = 0; i < n; ++ i){
        tot += a[i] - i;
    }
    if (tot & 1){
        puts("cslnb");
    }
    else{
        puts("sjfnb");
    }
    return 0;
}