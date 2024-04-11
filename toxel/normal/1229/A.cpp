#include <bits/stdc++.h>

const int N = 7010;
typedef long long ll;

ll a[N], b[N];
std::bitset <N> set[N];
int deg[N];
bool vis[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &b[i]);
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j) {
            if (a[i] & ~a[j]){
                set[i][j] = true;
                ++ deg[i];
            }
        }
    }
    ll sum = 0;
    for (int i = 0; i < n; ++ i){
        bool flag = true;
        for (int j = 0; j < n; ++ j){
            if (!vis[j] && deg[j] == n - i - 1){
                vis[j] = true;
                flag = false;
                for (int k = 0; k < n; ++ k){
                    if (set[k][j]){
                        -- deg[k];
                    }
                }
                break;
            }
        }
        if (flag){
            for (int j = 0; j < n; ++ j){
                if (!vis[j]){
                    sum += b[j];
                }
            }
            break;
        }
    }
    printf("%lld\n", sum);
    return 0;
}