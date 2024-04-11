#include <bits/stdc++.h>

const int N = 200010;
typedef long long ll;

int x[N], y[N], c[N], c1[N];
std::vector <int> vec[N];

void add(int sit, int value){
    for ( ; sit < N; sit += sit & -sit) {
        c1[sit] += value;
    }
}

int query(int sit){
    int ret = 0;
    for ( ; sit; sit -= sit & -sit){
        ret += c1[sit];
    }
    return ret;
}

int query(int l, int r){
    if (l > r){
        return 0;
    }
    return query(r) - query(l - 1);
}

ll calc(int n){
    return 1ll * n * (n + 1) / 2;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 0; i < n; ++ i){
        c[i] = x[i];
    }
    std::sort(c, c + n);
    int cnt = std::unique(c, c + n) - c;
    for (int i = 0; i < n; ++ i){
        x[i] = std::lower_bound(c, c + cnt, x[i]) - c + 1;
    }
    for (int i = 0; i < n; ++ i){
        c[i] = y[i];
    }
    std::sort(c, c + n);
    cnt = std::unique(c, c + n) - c;
    for (int i = 0; i < n; ++ i){
        y[i] = std::lower_bound(c, c + cnt, y[i]) - c + 1;
    }
    for (int i = 0; i < n; ++ i){
        vec[y[i]].push_back(x[i]);
    }
    for (int i = 0; i < N; ++ i){
        std::sort(vec[i].begin(), vec[i].end());
        vec[i].erase(std::unique(vec[i].begin(), vec[i].end()), vec[i].end());
    }
    ll ans = 0;
    for (int i = N - 1; i >= 0; -- i){
        if (vec[i].empty()){
            continue;
        }
        int sz = vec[i].size();
        for (int j = 0; j < sz - 1; ++ j){
            ans -= calc(query(vec[i][j] + 1, vec[i][j + 1] - 1));
        }
        ans -= calc(query(1, vec[i][0] - 1));
        ans -= calc(query(vec[i].back() + 1, N - 1));
        for (auto u : vec[i]){
            if (query(u, u) == 0){
                add(u, 1);
            }
        }
        ans += calc(query(1, N - 1));
    }
    printf("%lld\n", ans);
    return 0;
}