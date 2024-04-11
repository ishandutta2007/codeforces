#include <bits/stdc++.h>

const int N = 300010;
const int MAX = (int) 1e9;

using pii = std::pair <int, int>;
using piii = std::pair <pii, int>;
using ll = long long;

int l[N], r[N];
ll pre[N];
std::vector <piii> event[N];

ll check(int mid, int n, ll &sum){
    ll cnt = 0;
    sum = 0;
    memset(pre, 0, sizeof(pre));
    int pos = 0;
    ll pre_sum = 0, pre_sum1 = 0;
    for (int i = 1; i <= n; ++ i){
        for (auto u : event[i]){
            if (u.first.second > pos){
                pre[std::max(u.first.first, pos + 1)] += u.second;
                pre[u.first.second + 1] -= u.second;
            }
            int l = u.first.first, r = std::min(u.first.second, pos);
            if (l <= r){
                pre_sum1 += 1ll * (r - l + 1) * u.second;
            }
        }
        while (pos + 1 <= n && pre_sum + pre[pos + 1] >= mid){
            pre_sum += pre[pos + 1];
            pre_sum1 += pre_sum;
            ++ pos;
        }
        cnt += pos;
        sum += pre_sum1;
    }
    return cnt;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++ i){
        scanf("%d%d", &l[i], &r[i]);
        -- r[i];
    }
    std::set <piii> set;
    set.insert({{1, MAX}, 0});
    for (int i = 1; i <= n; ++ i){
        auto u = set.lower_bound({{l[i], INT_MIN}, INT_MIN});
        if (u != set.begin()){
            auto v = u;
            -- v;
            if (v != set.end() && v -> first.second >= l[i]){
                -- u;
            }
        }
        std::vector <piii> to_insert;
        to_insert.push_back({{l[i], r[i]}, i});
        while (u != set.end()){
            int l1 = u -> first.first, r1 = u -> first.second, max = u -> second;
            if (l1 > r[i]){
                break;
            }
            if (l[i] > l1){
                to_insert.push_back({{l1, l[i] - 1}, max});
            }
            if (r[i] < r1){
                to_insert.push_back({{r[i] + 1, r1}, max});
            }
            event[i].push_back({{max + 1, i}, std::min(r1, r[i]) - std::max(l1, l[i]) + 1});
            u = set.erase(u);
        }
        for (auto u : to_insert){
            set.insert(u);
        }
    }
    int left = 1, right = MAX + 10;
    while (left < right){
        int mid = (left + right + 1) / 2;
        ll tmp;
        if (check(mid, n, tmp) >= k){
            left = mid;
        }
        else{
            right = mid - 1;
        }
    }
    ll ans;
    ll cnt = check(left, n, ans);
    ans -= (cnt - k) * left;
    printf("%lld\n", ans);
}