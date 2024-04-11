#include<bits/stdc++.h>

typedef long long ll;

const int N = 100010;

ll x[N];
ll pre[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i += 2){
        scanf("%lld", &x[i]);
    }
    for (int i = 1; i <= n; ++ i){
        if (i & 1){
            std::vector <int> vec;
            for (int j = 1; j * j < x[i + 1]; ++ j){
                if (x[i + 1] % j == 0){
                    int u = j, v = x[i + 1] / j;
                    if ((u & 1) == (v & 1)){
                        vec.push_back((v - u) >> 1);
                    }
                }
            }
            std::reverse(vec.begin(), vec.end());
            bool flag = false;
            for (auto u : vec){
                if (1ll * u * u > pre[i - 1]){
                    x[i] = 1ll * u * u - pre[i - 1];
                    flag = true;
                    break;
                }
            }
            if (!flag){
                puts("No");
                return 0;
            }
        }
        pre[i] = pre[i - 1] + x[i];
    }
    puts("Yes");
    for (int i = 1; i <= n; ++ i){
        printf("%lld%c", x[i], " \n"[i == n]);
    }
    return 0;
}