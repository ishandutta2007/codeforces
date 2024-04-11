#include<bits/stdc++.h>

typedef long long ll;
const int N = 1000010;
const int moder = (int) 1e9 + 7;

void read(int &x){
    x = 0;
    char ch;
    while (!isdigit(ch = getchar()))
        ;
    x = ch - '0';
    while (isdigit(ch = getchar())){
        x = x * 10 + ch - '0';
    }
}

int a[N];
std::vector <int> e[N];
std::vector <ll> possible;
ll sum[N], tot;
int dp[N];

void dfs(int u){
    sum[u] = a[u];
    for (auto v : e[u]){
        dfs(v);
        sum[u] += sum[v];
    }
    if (tot % sum[u] == 0){
        possible.push_back(sum[u]);
    }
    if (sum[u] < tot && tot % (tot - sum[u]) == 0){
        possible.push_back(tot - sum[u]);
    }
}

void dfs1(int u){
    dp[u] = 1;
    for (auto v : e[u]){
        dfs1(v);
        dp[u] += dp[v];
        dp[u] -= dp[u] >= moder ? moder : 0;
    }
}

int main(){
    int n;
    read(n);
    //n = 720720;
    std::map <ll, int> Hash;
    for (int i = 1; i <= n; ++ i){
        read(a[i]);
        //a[i] = 1;
        tot += a[i];
    }
    for (int i = 2, x; i <= n; ++ i){
        read(x);
        //x = i - 1;
        e[x].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; ++ i){
        ++ Hash[std::__gcd(sum[i], tot)];
    }
    std::sort(possible.begin(), possible.end());
    possible.erase(std::unique(possible.begin(), possible.end()), possible.end());
    std::vector <ll> vec;
    for (auto u : possible){
        int cnt = 0;
        for (auto v : Hash){
            if (v.first % u == 0){
                cnt += v.second;
            }
        }
        if (cnt == tot / u){
            vec.push_back(u);
        }
    }
    for (int i = 0; i < N; ++ i){
        e[i].clear();
    }
    for (int i = 0, sz = vec.size(); i < sz; ++ i){
        for (int j = i + 1; j < sz; ++ j){
            if (vec[j] % vec[i] == 0){
                e[j].push_back(i);
            }
        }
    }
    dfs1(vec.size() - 1);
    printf("%d\n", dp[vec.size() - 1]);
    return 0;
}