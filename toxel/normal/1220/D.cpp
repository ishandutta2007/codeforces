#include <bits/stdc++.h>

const int N = 200010;
typedef long long ll;

ll a[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
    }
    int ans = INT_MAX;
    std::vector <ll> ret;
    for (int i = 0; i < 62; ++ i){
        int cnt = 0;
        std::vector <ll> tmp;
        for (int j = 0; j < n; ++ j){
            if (a[j] % (1ll << i)){
                ++ cnt;
                tmp.push_back(a[j]);
            }
            else if (a[j] % (1ll << (i + 1)) == 0){
                ++ cnt;
                tmp.push_back(a[j]);
            }
        }
        if (ans > cnt){
            ans = cnt;
            ret = tmp;
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < ans; ++ i){
        printf("%lld%c", ret[i], " \n"[i == ans - 1]);
    }
    return 0;
}