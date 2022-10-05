#include <bits/stdc++.h>

const int N = 500010;

int a[N], pre[N];
int l[N], r[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        pre[i] = pre[i - 1] + !a[i];
    }
    for (int i = 0; i <= n; ++ i){
        l[i] = r[i] = 0;
    }
    for (int i = 1; i <= n; ++ i){
        if (!a[i]){
            continue;
        }
        int left = pre[i], right = pre[n] - pre[i];
        if (left <= right){
            l[a[i]] = std::max(l[a[i]], left);
        }
        if (left >= right){
            r[a[i]] = std::max(r[a[i]], right);
        }
    }
    using pii = std::pair <int, int>;
    std::vector<pii> vec;
    for (int i = 1; i <= n; ++ i){
        if (l[i] || r[i]){
            vec.emplace_back(-l[i] + 1, r[i]);
        }
    }
    std::sort(vec.begin(), vec.end());
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int ans = 0, sz = vec.size();
    for (int i = -n, j = 0; i <= n; ++ i){
        while (j < sz && vec[j].first <= i){
            pq.emplace(vec[j].second);
            ++ j;
        }
        while (!pq.empty() && pq.top() < i){
            pq.pop();
        }
        if (!pq.empty()){
            ++ ans;
            pq.pop();
        }
    }
    ans = std::min(ans, pre[n] / 2);
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}