#include <bits/stdc++.h>

const int N = 100010;
const int SIGMA = 26;
using pii = std::pair <int, int>;
using ll = long long;

char s[N], t[N];
std::vector <int> vec[SIGMA];
int c[N];
std::vector <pii> rollback;

void add(int sit, int value){
    rollback.emplace_back(sit, value);
    for (sit += 1; sit < N; sit += sit & -sit){
        c[sit] += value;
    }
}

int query(int sit){
    int ans = 0;
    for (sit += 1; sit; sit -= sit & -sit){
        ans += c[sit];
    }
    return ans;
}

void solve(){
    int n;
    scanf("%d%s%s", &n, s, t);
    for (int i = 0; i < SIGMA; ++ i){
        vec[i].clear();
    }
    for (int i = 0; i < n; ++ i){
        vec[s[i] - 'a'].emplace_back(i);
    }
    for (int i = 0; i < SIGMA; ++ i){
        std::reverse(vec[i].begin(), vec[i].end());
    }
    ll ans = LLONG_MAX;
    ll cur = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < t[i] - 'a'; ++ j){
            if (vec[j].empty()){
                continue;
            }
            int pos = vec[j].back();
            int now = query(N - 2) - query(pos) + pos - i;
            if (cur + now < ans){
                ans = cur + now;
            }
        }
        int j = t[i] - 'a';
        if (vec[j].empty()){
            break;
        }
        int pos = vec[j].back();
        int now = query(N - 2) - query(pos) + pos - i;
        cur += now;
        vec[j].pop_back();
        add(pos, 1);
    }
    for (auto [k, v]: rollback){
        for (k += 1; k < N; k += k & -k){
            c[k] -= v;
        }
    }
    rollback.clear();
    if (ans == LLONG_MAX){
        ans = -1;
    }
    printf("%lld\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}