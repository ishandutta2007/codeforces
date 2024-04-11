#include <bits/stdc++.h>

const double PI = std::acos(-1.0);

double calc(int n, double shift){
    double minx = 1e100, miny = 1e100;
    double maxx = -1e100, maxy = -1e100;
    for (int i = 0; i < n; ++ i){
        double angle = 2 * PI / n * i + shift;
        double x = std::cos(angle);
        double y = std::sin(angle);
        minx = std::min(minx, x);
        miny = std::min(miny, y);
        maxx = std::max(maxx, x);
        maxy = std::max(maxy, y);
    }
    return std::max(maxx - minx, maxy - miny);
}

void solve(){
    int n;
    scanf("%d", &n);
    if (n % 2 == 0){
        double angle = 2 * PI / (2 * n) / 2;
        double ans = 1 / std::tan(angle);
        printf("%.15f\n", ans);
    }
    else{
        n *= 2;
        double angle = 2 * PI / n;
        double left = 0, right = angle;
        for (int _ = 0; _ < 100; ++ _){
            double mid1 = (2 * left + right) / 3, mid2 = (left + 2 * right) / 3;
            if (calc(n, mid1) < calc(n, mid2)){
                right = mid2;
            }
            else{
                left = mid1;
            }
        }
        printf("%.15f\n", calc(n, left) / std::sin(angle / 2) / 2);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}