#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair <int, int> pii;

const int N = 100010;

int a[N];

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &k, &m);
    std::deque <pii> queue;
    for (int i = 0, x; i < n; ++ i){
        scanf("%d", &x);
        bool flag = !queue.empty() && x == queue.back().first;
        if (flag && queue.back().second == k - 1){
            for (int j = 0; j < k - 1; ++ j){
                queue.pop_back();
            }
        }
        else{
            if (flag){
                queue.push_back({x, queue.back().second + 1});
            }
            else{
                queue.push_back({x, 1});
            }
        }
    }
    n = 0;
    for (auto u : queue){
        a[n ++] = u.first;
    }
    if (!n){
        puts("0");
        return 0;
    }
    int left = 0, right = n - 1;
    while (left <= right){
        int tmp = a[left], cnt = 0;
        while (left <= right && a[left] == tmp){
            ++ cnt;
            ++ left;
        }
        while (left <= right && a[right] == tmp){
            ++ cnt;
            -- right;
        }
        if (left > right){
            if (1ll * m * cnt % k == 0){
                puts("0");
            }
            else{
                printf("%lld\n", 1ll * m * cnt % k + n - cnt);
            }
            return 0;
        }
        if (cnt % k){
            printf("%lld\n", 1ll * (right - left + 1) * m + 1ll * (cnt % k) * (m - 1) + n - (right - left + 1));
            return 0;
        }
    }
    return 0;
}