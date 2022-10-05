#include<bits/stdc++.h>

const int N = 300010;
typedef long long ll;

char s[N];

int main(){
    int n, x, y;
    scanf("%d%d%d%s", &n, &x, &y, s);
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '0' && s[i + 1] != '0'){
            ++ cnt;
        }
    }
    if (!cnt){
        puts("0");
        return 0;
    }
    ll ans = 1ll * std::min(x, y) * (cnt - 1) + y;
    printf("%lld\n", ans);
    return 0;
}