#include <bits/stdc++.h>

const int N = 110;
const int M = 300010;
using ll = long long;

int sg[N][3];
ll a[M];

int solve(){
    int n, x, y, z;
    scanf("%d%d%d%d", &n, &x, &y, &z);
    for (int i = 1; i < N; ++ i){
        for (int j = 0; j < 3; ++ j){
            std::set <int> set;
            set.insert(sg[std::max(i - x, 0)][0]);
            if (j != 1){
                set.insert(sg[std::max(i - y, 0)][1]);
            }
            if (j != 2){
                set.insert(sg[std::max(i - z, 0)][2]);
            }
            for (int k = 0; ; ++ k){
                if (!set.count(k)){
                    sg[i][j] = k;
                    break;
                }
            }
        }
    }
    int period;
    for (int i = 1; ; ++ i){
        bool flag = true;
        for (int j = N / 2; j + i < N; ++ j){
            for (int k = 0; k < 3; ++ k){
                if (sg[j][k] != sg[j + i][k]){
                    flag = false;
                    break;
                }
            }
        }
        if (flag){
            period = i;
            break;
        }
    }
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
        if (a[i] > N / 2){
            a[i] -= (a[i] - N / 2) / period * period;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++ i){
        sum ^= sg[a[i]][0];
    }
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        int xx = sum ^ sg[a[i]][0];
        if (sg[std::max(a[i] - x, 0ll)][0] == xx){
            ++ cnt;
        }
        if (sg[std::max(a[i] - y, 0ll)][1] == xx){
            ++ cnt;
        }
        if (sg[std::max(a[i] - z, 0ll)][2] == xx){
            ++ cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}