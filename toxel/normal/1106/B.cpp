#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair <int, int> pii;
const int N = 100010;

int a[N], c[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    std::set <pii> set;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &c[i]);
        set.insert({c[i], i});
    }
    bool flag = false;
    for (int i = 0; i < m; ++ i){
        int t, d;
        scanf("%d%d", &t, &d);
        if (flag){
            puts("0");
            continue;
        }
        -- t;
        ll tmpans = 0;
        if (a[t]){
            int x = std::min(a[t], d);
            tmpans += 1ll * x * c[t];
            d -= x;
            a[t] -= x;
            if (!a[t]){
                set.erase({c[t], t});
            }
        }
        while (d){
            if (set.empty()){
                flag = true;
                break;
            }
            int sit = set.begin() -> second;
            int x = std::min(d, a[sit]);
            tmpans += 1ll * x * c[sit];
            d -= x;
            a[sit] -= x;
            if (!a[sit]){
                set.erase(set.begin());
            }
        }
        printf("%lld\n", flag ? 0ll : tmpans);
    }
    return 0;
}