#include <bits/stdc++.h>

const int N = 200010;
using ll = long long;

int type[N];
int tl[N], c[N];
int ccnt[N][2];

void solve(){
    int n, t, a, b;
    scanf("%d%d%d%d", &n, &t, &a, &b);
    int tot[2] = {};
    for (int i = 0; i < n; ++ i){
        scanf("%d", &type[i]);
        ++ tot[type[i]];
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &tl[i]);
        c[i] = tl[i];
    }
    c[n] = t;
    std::sort(c, c + n + 1);
    int cnt = std::unique(c, c + n + 1) - c;
    for (int i = 0; i < cnt; ++ i){
        ccnt[i][0] = ccnt[i][1] = 0;
    }
    for (int i = 0; i < n; ++ i){
        tl[i] = std::lower_bound(c, c + cnt, tl[i]) - c;
        ++ ccnt[tl[i]][type[i]];
    }
    int ans = 0;
    int cur[2] = {};
    for (int i = 0; i <= cnt; ++ i){
        if (i < cnt && c[i] == 0){
            for (int j = 0; j < 2; ++ j){
                cur[j] += ccnt[i][j];
            }
            continue;
        }
        int max = i == cnt ? t : c[i] - 1;
        ll used = 1ll * cur[0] * a + 1ll * cur[1] * b;
        if (used > max){
            for (int j = 0; j < 2; ++ j){
                cur[j] += ccnt[i][j];
            }
            continue;
        }
        max -= used;
        int solved = cur[0] + cur[1];
        if (max <= 1ll * (tot[0] - cur[0]) * a){
            solved += max / a;
        }
        else{
            solved += tot[0] - cur[0];
            max -= 1ll * (tot[0] - cur[0]) * a;
            solved += std::min(max / b, tot[1] - cur[1]);
        }
        ans = std::max(ans, solved);
        if (i < cnt){
            for (int j = 0; j < 2; ++ j){
                cur[j] += ccnt[i][j];
            }
        }
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}