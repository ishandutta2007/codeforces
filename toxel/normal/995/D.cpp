#include<bits/stdc++.h>

const int N = 1 << 18;
typedef long long ll;

int a[N];

int main(){
    int n, r;
    scanf("%d%d", &n, &r);
    ll sum = 0;
    for (int i = 0; i < 1 << n; ++ i){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    printf("%.10lf\n", 1.0 * sum / (1 << n));
    for (int i = 0; i < r; ++ i){
        int sit, value;
        scanf("%d%d", &sit, &value);
        sum -= a[sit];
        a[sit] = value;
        sum += value;
        printf("%.10lf\n", 1.0 * sum / (1 << n));
    }
    return 0;
}