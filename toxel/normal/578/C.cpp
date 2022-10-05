#include<bits/stdc++.h>

const int N = 200010;

int a[N];
double b[N];

double calc(int n, double x){
    for (int i = 1; i <= n; ++ i){
        b[i] = a[i - 1] - x;
        b[i] += b[i - 1];
    }
    double max = 0, min = 0;
    for (int i = 1; i <= n; ++ i){
        max = std::max(max, b[i]);
        min = std::min(min, b[i]);
    }
    return max - min;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    double left = -1.1e4, right = 1.1e4;
    for (int i = 0; i < 100; ++ i){
        double mid1 = (2 * left + right) / 3, mid2 = (left + 2 * right) / 3;
        double x1 = calc(n, mid1), x2 = calc(n, mid2);
        if (x1 < x2){
            right = mid2;
        }
        else{
            left = mid1;
        }
    }
    printf("%.10lf\n", calc(n, left));
    return 0;
}