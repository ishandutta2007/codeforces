#include <bits/stdc++.h>

const int N = 100010;

int a[N];

void solve(){
    int n, l;
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    a[n + 1] = l;
    double left = 0, right = 1.1e9;
    for (int _ = 0; _ < 70; ++ _){
        double mid = (left + right) / 2;
        double dis = 0, time = mid;
        for (int i = 1; i <= n + 1; ++ i){
            double need = 1.0 * (a[i] - a[i - 1]) / i;
            if (time < need){
                dis += i * time;
                break;
            }
            else{
                dis += a[i] - a[i - 1];
                time -= need;
            }
        }
        double dis1 = 0;
        time = mid;
        for (int i = n; i >= 0; -- i){
            double need = 1.0 * (a[i + 1] - a[i]) / (n - i + 1);
            if (time < need){
                dis1 += (n - i + 1) * time;
                break;
            }
            else{
                dis1 += a[i + 1] - a[i];
                time -= need;
            }
        }
        if (dis + dis1 >= l){
            right = mid;
        }
        else{
            left = mid;
        }
    }
    printf("%.15f\n", left);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}