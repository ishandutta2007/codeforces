#include<bits/stdc++.h>

typedef long long ll;

const int N = 200010;

ll ans[N];

int main(){
    std::map <ll, int> Hash;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        ll l, r;
        scanf("%lld%lld", &l, &r);
        ++ Hash[l];
        -- Hash[r + 1];
    }
    int now = 0;
    ll pre = 0;
    for (auto u : Hash){
        if (now){
            ans[now] += u.first - pre;
        }
        now += u.second;
        pre = u.first;
    }
    for (int i = 1; i <= n; ++ i){
        printf("%lld%c", ans[i], " \n"[i == n]);
    }
    return 0;
}