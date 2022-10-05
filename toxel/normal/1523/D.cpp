#include <bits/stdc++.h>

using ll = long long;
const int N = 200010;
const int M = 70;
const int K = 16;

char like[N][M];
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
int cnt[1 << K], bitcnt[1 << K];

void solve(){
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    /*n = 200000;
    m = 60;
    p = 15;*/
    for (int i = 0; i < n; ++ i){
        scanf("%s", like[i]);
        /*&for (int j = 0; j < m; ++ j){
            like[i][j] = j < p ? rnd() % 2 + '0' : '0';
        }*/
    }
    int ans = -1;
    char output[M] = {};
    for (int _ = 0; _ < 30; ++ _){
        int person = rnd() % n;
        memset(cnt, 0, sizeof(cnt));
        int len = 0;
        for (int i = 0; i < n; ++ i){
            int ccnt = 0, state = 0;
            for (int j = 0; j < m; ++ j){
                if (like[person][j] == '1'){
                    state |= (like[i][j] - '0') << ccnt;
                    ++ ccnt;
                }
            }
            ++ cnt[state];
            len = ccnt;
        }
        for (int j = 0; j < len; ++ j){
            for (int i = (1 << len) - 1; i >= 0; -- i){
                if (!(i >> j & 1)){
                    cnt[i] = cnt[i] + cnt[i ^ 1 << j];
                }
            }
        }
        for (int i = 0; i < 1 << len; ++ i){
            if (cnt[i] >= (n + 1) / 2){
                if (bitcnt[i] > ans){
                    ans = bitcnt[i];
                    int ccnt = 0;
                    for (int j = 0; j < m; ++ j){
                        if (like[person][j] == '1'){
                            output[j] = (i >> ccnt & 1) + '0';
                            ++ ccnt;
                        }
                        else{
                            output[j] = '0';
                        }
                    }
                    output[m] = '\0';
                }
            }
        }
    }
    puts(output);
}

int main(){
    for (int i = 1; i < 1 << K; ++ i){
        bitcnt[i] = bitcnt[i >> 1] + (i & 1);
    }
    int test = 1;
    while (test --){
        solve();
    }
    return 0;
}