#include<bits/stdc++.h>

const int N = 5100010;
const int M = 200010;
const int K = 1100010;
const int U = 10;
typedef std::pair <int, int> pii;

int min[N], ans[K], a[M], dp[N][U];
int best[U << 1];
std::vector <int> prime;
std::vector <pii> vec[M];

void init(){
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            prime.push_back(i);
        }
        for (int j = 0, sz = prime.size(); j < sz && i * prime[j] < N; ++ j){
            min[i * prime[j]] = prime[j];
            if (i % prime[j] == 0){
                break;
            }
        }
    }
}

int main(){
    init();
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < q; ++ i){
        int l, r;
        scanf("%d%d", &l, &r);
        -- l, -- r;
        vec[r].push_back({l, i});
    }
    memset(best, -1, sizeof(best));
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++ i){
        std::vector <int> p;
        int x = a[i];
        while (x > 1){
            int tmp = min[x], cnt = 0;
            while (x % tmp == 0){
                x /= tmp;
                ++ cnt;
            }
            if (cnt & 1){
                p.push_back(tmp);
            }
        }
        int sz = p.size();
        for (int j = 0; j < 1 << sz; ++ j){
            int prod = 1, cnt = sz;
            for (int k = 0; k < sz; ++ k){
                if (j >> k & 1){
                    prod *= p[k];
                    -- cnt;
                }
            }
            best[cnt << 1] = std::max(best[cnt << 1], dp[prod][cnt]) ;
            dp[prod][cnt] = i;
            for (int k = 0; k < U; ++ k){
                if (k == cnt) continue;
                best[k + cnt] = std::max(best[k + cnt], dp[prod][k]);
            }
        }
        for (auto u : vec[i]){
            for (int j = (U << 1) - 1; j >= 0; -- j){
                if (u.first <= best[j]){
                    ans[u.second] = j;
                }
            }
        }
    }
    for (int i = 0; i < q; ++ i){
        printf("%d\n", ans[i]);
    }
    return 0;
}