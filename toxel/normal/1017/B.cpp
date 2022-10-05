#include<bits/stdc++.h>

const int N = 100010;
typedef long long ll;

char s[N], t[N];
int cnt[N];

bool diff(int i, int j){
    int i1 = i >> 1, i2 = i & 1, j1 = j >> 1, j2 = j & 1;
    return (i1 | i2) != (j1 | i2) || (j1 | j2) != (i1 | j2);
}

int main(){
    int n;
    scanf("%d%s%s", &n, s, t);
    for (int i = 0; i < n; ++ i){
        ++ cnt[(s[i] - '0' << 1) | (t[i] - '0')];
    }
    ll ans = 0;
    for (int i = 0; i < 4; ++ i){
        for (int j = i + 1; j < 4; ++ j){
            if (diff(i, j)){
                ans += 1ll * cnt[i] * cnt[j];
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}