#include <bits/stdc++.h>

const int N = 501;
using ll = long long;
ll INF = 8e18;
int moder;

void add(int &u, int v){
    u += v;
    u -= u >= moder ? moder : 0;
}

std::vector <int> inv[N];

int main(){
    int n;
    scanf("%d%d", &n, &moder);
    inv[1] = {1};
    for (int i = 2; i <= n; ++ i){
        int sz = inv[i - 1].size(), sz1 = sz + i - 1;
        inv[i].resize(sz1);
        auto get_prev = [&](int pos){
            if (pos < 0) return 0;
            if (pos >= sz) return inv[i - 1].back();
            return inv[i - 1][pos];
        };
        for (int j = 0; j < sz1; ++ j){
            inv[i][j] = get_prev(j) - get_prev(j - i);
            inv[i][j] += inv[i][j] < 0 ? moder : 0;
        }
        for (int j = 1; j < sz1; ++ j){
            add(inv[i][j], inv[i][j - 1]);
        }
    }
    int ans = 0;
    for (int i = 3; i <= n; ++ i){
        auto get_pos = [&](int pos){
            if (pos == 0) return inv[i - 1][0];
            int x = inv[i - 1][pos] - inv[i - 1][pos - 1];
            x += x < 0 ? moder : 0;
            return x;
        };
        std::vector <int> prev = inv[i - 1];
        int sz = prev.size();
        for (int j = 1; j < sz; ++ j){
            add(prev[j], prev[j - 1]);
        }
        auto calc = [&](int pos){
            if (pos == 0){
                return 0;
            }
            if (pos < i){
                int ans = (1ll * i * inv[i - 1][pos - 1] - prev[pos - 1]) % moder;
                ans += ans < 0 ? moder : 0;
                return ans;
            }
            int ans = ((prev[pos - 1] - prev[pos - i]) - 1ll * (i - 1) * inv[i - 1][pos - i]) % moder;
            ans = (1ll * i * (inv[i - 1][pos - 1] - inv[i - 1][pos - i]) - ans) % moder;
            ans += ans < 0 ? moder : 0;
            return ans;
        };
        ll sum = 0;
        int cur = 0;
        for (int j = 0; j < sz; ++ j){
            int x = get_pos(j);
            sum += 1ll * x * cur;
            add(cur, calc(j));
            if (sum > INF){
                sum %= moder;
            }
        }
        sum %= moder;
        for (int j = n; j > i; -- j){
            sum = 1ll * sum * j % moder;
        }
        add(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}