#include<bits/stdc++.h>

const int N = 200010;

int a[N], b[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; ++ i){
        if (a[i] == 0){
            for (int j = i; j < n - 1; ++ j){
                a[j] = a[j + 1];
            }
            a[n - 1] = 0;
            break;
        }
    }
    for (int i = 0; i < n; ++ i){
        if (b[i] == a[0]){
            std::rotate(b, b + i, b + n);
        }
    }
    for (int i = 0; i < n; ++ i){
        if (b[i] == 0){
            for (int j = i; j < n - 1; ++ j){
                b[j] = b[j + 1];
            }
            b[n - 1] = 0;
            break;
        }
    }
    for (int i = 0; i < n; ++ i){
        if (b[i] != a[i]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}