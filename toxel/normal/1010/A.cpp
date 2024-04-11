#include<bits/stdc++.h>

const int N = 1010;

int a[N], b[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &b[i]);
    }
    double ans = 0;
    for (int i = n - 1; i >= 0; -- i){
        if (a[i] == 1 || b[i] == 1){
            puts("-1");
            return 0;
        }
        ans = 1.0 * m / (b[i] - 1) + ans * b[i] / (b[i] - 1);
        ans = 1.0 * m / (a[i] - 1) + ans * a[i] / (a[i] - 1);
    }
    printf("%.15f\n", ans);
    return 0;
}