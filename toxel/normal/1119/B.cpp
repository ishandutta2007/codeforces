#include <bits/stdc++.h>

const int N = 1010;
typedef long long ll;

int a[N], b[N];

int main(){
    int n, h;
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = n; i >= 1; -- i){
        for (int j = 1; j <= i; ++ j){
            b[j] = a[j];
        }
        std::sort(b + 1, b + i + 1, std::greater <int>());
        ll sum = 0;
        for (int j = 1; j <= i; j += 2){
            sum += b[j];
        }
        if (sum <= h){
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}