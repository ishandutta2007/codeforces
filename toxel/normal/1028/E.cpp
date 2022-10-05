#include<bits/stdc++.h>

const int N = 400010;
typedef long long ll;
const ll INF = 1e10;

int n;
ll a[N];
int b[N];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &b[i]);
    }
    bool flag = true;
    for (int i = 0; i < n - 1; ++ i){
        if (b[i] != b[i + 1]){
            flag = false;
            break;
        }
    }
    if (flag){
        if (b[0] != 0){
            puts("NO");
        }
        else{
            puts("YES");
            for (int i = 0; i < n; ++ i){
                printf("%d%c", 1, " \n"[i == n - 1]);
            }
        }
        return 0;
    }
    for (int i = n; i < 2 * n; ++ i){
        b[i] = b[i - n];
    }
    int sit;
    for (int i = 0; i < n; ++ i){
        if (b[(i - 1 + n) % n] < b[i]){
            sit = i;
        }
    }
    a[sit + n] = b[sit + n];
    a[sit + n - 1] = INF * b[sit + n] + b[sit + n - 1];
    for (int i = sit + n - 2; i >= sit + 1; -- i){
        a[i] = a[i + 1] + b[i];
    }
    for (int i = 0; i <= sit; ++ i){
        a[i] = a[i + n];
    }
    puts("YES");
    for (int i = 0; i < n; ++ i){
        printf("%lld%c", a[i], " \n"[i == n - 1]);
    }
    return 0;
}