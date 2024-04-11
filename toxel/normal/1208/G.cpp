#include <bits/stdc++.h>

const int N = 1000010;
typedef long long ll;

int min[N], phi[N];
int cnt[N];
std::vector <int> prime;

int main(){
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            phi[i] = i - 1;
            prime.push_back(i);
        }
        for (auto u : prime){
            if (i * u >= N){
                break;
            }
            min[i * u] = u;
            if (i % u == 0){
                phi[i * u] = phi[i] * u;
                break;
            }
            phi[i * u] = phi[i] * (u - 1);
        }
    }
    int n, k;
    scanf("%d%d", &n, &k);
    if (k == 1){
        puts("3");
        return 0;
    }
    for (int i = 3; i <= n; i += 2){
        ++ cnt[phi[i]];
    }
    auto getans = [&](int k){
        std::vector <int> ccnt(N);
        std::copy(cnt, cnt + N, ccnt.begin());
        ll ans = 1;
        for (int i = 0; i < N && k; ++ i){
            while (ccnt[i] && k){
                -- ccnt[i], -- k;
                ans += i;
            }
        }
        return k ? 0x3f3f3f3f3f3f3f3f : ans;
    };
    ll ans = getans(k);
    for (int i = 4; i <= n; i += 2){
        ++ cnt[phi[i]];
    }
    ans = std::min(getans(k) + 1, ans);
    printf("%lld\n", ans);
    return 0;
}