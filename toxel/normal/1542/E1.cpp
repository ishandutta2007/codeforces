#include <bits/stdc++.h>

const int N = 501;
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
        int sum = 0;
        auto get_pos = [&](int pos){
            if (pos == 0) return inv[i - 1][0];
            int x = inv[i - 1][pos] - inv[i - 1][pos - 1];
            x += x < 0 ? moder : 0;
            return x;
        };
        for (int diff = 1; diff < i; ++ diff){
            int sum1 = 0, sz = inv[i - 1].size();
            for (int j = 0; j < sz; ++ j){
                int x = get_pos(j);
                int pos = j - (diff + 1);
                int y = pos < 0 ? 0 : inv[i - 1][pos];
                sum1 = (sum1 + 1ll * x * y) % moder;
            }
            sum = (sum + 1ll * sum1 * (i - diff)) % moder;
        }
        for (int j = n; j > i; -- j){
            sum = 1ll * sum * j % moder;
        }
        add(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}