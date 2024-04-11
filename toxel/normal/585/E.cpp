#include<bits/stdc++.h>

const int N = (int) 1e7 + 10;
const int M = (int) 5e5 + 10;
const int moder = (int) 1e9 + 7;

int min[N], mu[N], tmp[N];
std::vector <int> prime;
int cnt[N];
int power[M];

int main(){
    mu[1] = 1;
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            mu[i] = -1;
            prime.push_back(i);
        }
        for (int j = 0, k; j < prime.size() && i * prime[j] < N; ++ j){
            min[k = i * prime[j]] = prime[j];
            if (i % prime[j] == 0){
                mu[k] = 0;
                break;
            }
            mu[k] = -mu[i];
        }
    }
    power[0] = 1;
    for (int i = 1; i < M; ++ i){
        power[i] = power[i - 1] << 1;
        power[i] -= power[i] >= moder ? moder : 0;
    }
    for (int i = 0; i < M; ++ i){
        -- power[i];
        power[i] += power[i] < 0 ? moder : 0;
    }
    int n;
    scanf("%d", &n);
    for (int i = 0, x; i < n; ++ i){
        scanf("%d", &x);
        ++ cnt[x];
        ++ tmp[x];
    }
    for (int i = 1; i < N; ++ i){
        for (int j = i << 1; j < N; j += i){
            cnt[i] += cnt[j];
        }
        cnt[i] = power[cnt[i]];
    }
    int one = 0;
    for (int i = 1; i < N; ++ i){
        one += mu[i] * cnt[i];
        one -= one >= moder ? moder : 0;
        one += one < 0 ? moder : 0;
    }
    for (int i = N - 1; i >= 1; -- i){
        for (int j = i << 1; j < N; j += i){
            cnt[j] += cnt[i] * mu[i];
            cnt[j] -= cnt[j] >= moder ? moder : 0;
            cnt[j] += cnt[j] < 0 ? moder : 0;
        }
        cnt[i] *= mu[i];
        cnt[i] += cnt[i] < 0 ? moder : 0;
    }
    int ans = 1ll * tmp[1] * power[n - 1] % moder;
    for (int i = 2; i < N; ++ i){
        cnt[i] -= one;
        cnt[i] += cnt[i] < 0 ? moder : 0;
        ans = (ans + 1ll * cnt[i] * tmp[i]) % moder;
    }
    printf("%d\n", ans);
    return 0;
}