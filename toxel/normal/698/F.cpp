#include<bits/stdc++.h>

const int N = 1000010;
const int M = 1010;
const int moder = 1e9 + 7;

typedef std::pair <int, int> pii;

int fac[N];
int min[N];
int sz[N];
int p[N];
int f[N];
std::vector <int> prime;
int cnt[N], ccnt[N];
int tocnt[N];

std::vector <int> decomp(int n){
    std::vector <int> ret;
    while (min[n] > 1){
        int tmp = min[n];
        while (n % tmp == 0){
            n /= tmp;
        }
        ret.push_back(tmp);
    }
    if (ret.empty()){
        ret.push_back(1);
    }
    return ret;
}

int prod(std::vector <int> vec){
    int ret = 1;
    for (auto u : vec){
        ret *= u;
    }
    return ret;
}

void no(){
    puts("0");
    exit(0);
}

int main(){
    fac[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
    }
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
    }
    sz[1] = 1;
    cnt[1] = 1;
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            sz[i] = n / i;
            ++ cnt[sz[i]];
            prime.push_back(i);
        }
        for (int j = 0, k; j < prime.size() && i * prime[j] < N; ++ j){
            min[k = i * prime[j]] = prime[j];
            if (i % prime[j] == 0){
                break;
            }
        }
    }
    std::map <std::vector <int>, int> Hash;
    for (int i = 1; i <= n; ++ i){
        std::vector <int> from = decomp(i);
        if (p[i]){
            std::vector <int> to = decomp(p[i]);
            if (from.size() != to.size()) no();
            for (int j = 0, sz = from.size(); j < sz; ++ j){
                if (::sz[from[j]] != ::sz[to[j]]) no();
                if (f[from[j]] && f[from[j]] != to[j]) no();
                f[from[j]] = to[j];
            }

            -- ccnt[prod(to)];
        }
        ++ ccnt[prod(from)];
    }
    for (int i = 0; i < N; ++ i){
        ++ tocnt[f[i]];
    }
    for (int j = 1; j < N; ++ j){
        if (tocnt[j] > 1) no();
    }
    for (int i = 1; i <= n; ++ i){
        if (f[i]){
            -- cnt[sz[f[i]]];
        }
    }
    int ans = 1;
    for (int i = 1; i < N; ++ i){
        ans = 1ll * ans * fac[cnt[i]] % moder;
        ans = 1ll * ans * fac[ccnt[i]] % moder;
    }
    printf("%d\n", ans);
    return 0;
}