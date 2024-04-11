#include <bits/stdc++.h>

using ll = long long;
const int N = 110000;
const int INF = 100010;

int a[N];
std::vector <int> vec[N];
ll sum[N];
int avg[N], num[N];
int available[N][3];

bool check(int l, int r, int id){
    if (l > r) return true;
    int num = available[r][id] - (l == 0 ? 0 : available[l - 1][id]);
    return num == r - l + 1;
}

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        a[i] = INF - a[i];
    }
    std::sort(a, a + n);
    for (int i = 0; i < m; ++ i){
        vec[i].clear();
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; ++ j){
            int x;
            scanf("%d", &x);
            vec[i].emplace_back(INF - x);
        }
    }
    auto get_num = [&](int x){
        return int(std::upper_bound(a, a + n, x) - a);
    };
    for (int i = 0; i < m; ++ i){
        sum[i] = 0;
        for (auto u : vec[i]){
            sum[i] += u;
        }
        avg[i] = sum[i] / vec[i].size();
        num[i] = get_num(avg[i]);
    }
    std::vector <int> nums;
    for (int i = 0; i < m; ++ i){
        nums.emplace_back(num[i]);
    }
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < m; ++ i){
        for (int j = 0; j < 3; ++ j){
            available[i][j] = (i == 0 ? 0 : available[i - 1][j]) + (i + 1 <= nums[i] + j - 1);
        }
    }
    for (int i = 0; i < m; ++ i){
        int cur_num = num[i];
        int cur_pos = std::lower_bound(nums.begin(), nums.end(), cur_num) - nums.begin();
        for (auto u : vec[i]){
            int n_num = (sum[i] - u) / (vec[i].size() - 1);
            n_num = get_num(n_num);
            if (cur_num < n_num){
                int n_pos = std::upper_bound(nums.begin(), nums.end(), n_num) - nums.begin() - 1;
                if (check(0, cur_pos - 1, 1) && check(cur_pos + 1, n_pos, 2) && check(n_pos + 1, m - 1, 1) && n_pos + 1 <= n_num){
                    putchar('1');
                }
                else{
                    putchar('0');
                }
            }
            else if (cur_num == n_num){
                if (check(0, m - 1, 1)){
                    putchar('1');
                }
                else{
                    putchar('0');
                }
            }
            else{
                int n_pos = std::upper_bound(nums.begin(), nums.end(), n_num) - nums.begin();
                if (check(0, n_pos, 1) && check(n_pos + 1, cur_pos - 1, 0) && check(cur_pos + 1, m - 1, 1) && n_pos + 1 <= n_num){
                    putchar('1');
                }
                else{
                    putchar('0');
                }
            }
        }
    }
    puts("");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}