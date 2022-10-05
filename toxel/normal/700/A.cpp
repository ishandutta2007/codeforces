#include<bits/stdc++.h>

int main(){
    int n, l, v1, v2, k;
    scanf("%d%d%d%d%d", &n, &l, &v1, &v2, &k);
    n = (n + k - 1) / k;
    double left = 0, right = 1.0 * l / v2;
    for (int _ = 0; _ < 50; ++ _){
        double mid = (left + right) * 0.5;
        double nowr = 0, nowt = 0;
        for (int i = 0; i < n; ++ i){
            double nowl = nowt * v1;
            double t = (nowr - nowl) / (v1 + v2);
            nowr -= t * v2;
            nowt += t + mid;
            nowr += mid * v2;
        }
        if (nowr < l){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    printf("%.15f\n", left + (l - left * v2) / v1);
    return 0;
}