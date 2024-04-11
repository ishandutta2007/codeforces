#include<bits/stdc++.h>

const int N = 15000010;
const int INF = 0x7f7f7f7f;

int min[N];
int cnt[N];
int prime[N];
int sz;
int a[N];

void init(){
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            prime[sz ++] = i;
        }
        for (int j = 0; j < sz && i * prime[j] < N; ++ j){
            min[i * prime[j]] = prime[j];
            if (i % prime[j] == 0){
                break;
            }
        }
    }
}

int main(){
    init();
    int n;
    scanf("%d", &n);
    int gcd = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        gcd = std::__gcd(a[i], gcd);
    }
    for (int i = 0; i < n; ++ i){
        a[i] /= gcd;
        while (a[i] > 1){
            int tmp = min[a[i]];
            ++ cnt[tmp];
            while (a[i] % tmp == 0){
                a[i] /= tmp;
            }
        }
    }
    int ans = INF;
    for (int i = 2; i < N; ++ i){
        if (min[i] == i){
            if (cnt[i]){
                ans = std::min(ans, n - cnt[i]);
            }
        }
    }
    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}