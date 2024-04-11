#include <bits/stdc++.h>

const int N = 200010;
using pii = std::pair <int, int>;
const int INF = 0x3f3f3f3f;

int a[N], b[N];
int pos[N << 1];
int dp[N][2];

void update(int &u, int v, int w){
    if (v == INF){
        return;
    }
    v += w;
    u = std::min(u, v);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d%d", &a[i], &b[i]);
        pos[a[i]] = i;
        pos[b[i]] = i + n;
    }
    std::vector <pii> operate;
    std::set <int> set;
    for (int i = 1; i <= 2 * n; ++ i){
        set.insert(i);
    }
    while (!set.empty()){
        int min = *(set.begin());
        int max = *std::prev(set.end());
        auto uniform = [&](const int &a){
            return a > n ? a - n : a;
        };
        int pos1 = uniform(pos[min]), pos2 = uniform(pos[max]);
        if (pos1 == pos2){
            operate.emplace_back(pos1, 0);
            set.erase(a[pos1]);
            set.erase(b[pos1]);
        }
        else{
            operate.emplace_back(pos1, pos2);
            set.erase(a[pos1]);
            set.erase(b[pos1]);
            set.erase(a[pos2]);
            set.erase(b[pos2]);
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = dp[0][1] = 0;
    int a1 = -1, b1 = 2 * n + 1, a2 = 2 * n + 1, b2 = -1;
    int sz = operate.size();
    for (int i = 0; i < sz; ++ i){
        int pos1 = operate[i].first;
        int pos2 = operate[i].second;
        if (pos2 == 0){
            int min = std::min(a[pos1], b[pos1]);
            int max = std::max(a[pos1], b[pos1]);
            if (b1 > max && max > min && min > b2){
                dp[i + 1][0] = std::min(dp[i][0], dp[i][1]);
                a1 = -1, b1 = 2 * n + 1, a2 = 2 * n + 1, b2 = -1;
                continue;
            }
            if (b1 > max && max > b2){
                int rev = a[pos1] > b[pos1];
                for (int j = 0; j < 2; ++ j){
                    update(dp[i + 1][j], dp[i][j], rev ^ j);
                }
                a1 = min;
                b1 = max;
                continue;
            }
            else if (b1 > min && min > b2){
                int rev = a[pos1] < b[pos1];
                for (int j = 0; j < 2; ++ j){
                    update(dp[i + 1][j], dp[i][j], rev ^ j);
                }
                a2 = max;
                b2 = min;
            }
            else{
                puts("-1");
                return 0;
            }
        }
        else{
            int rev1 = a[pos1] > b[pos1];
            int rev2 = a[pos2] < b[pos2];
            if (a[pos1] > b[pos1]){
                std::swap(a[pos1], b[pos1]);
            }
            if (a[pos2] < b[pos2]){
                std::swap(a[pos2], b[pos2]);
            }
            if (!(a1 < a[pos1] && a[pos1] < a[pos2] && a[pos2] < a2)){
                puts("-1");
                return 0;
            }
            if (!(b1 > b[pos1] && b[pos1] > b[pos2] && b[pos2] > b2)){
                puts("-1");
                return 0;
            }
            update(dp[i + 1][0], dp[i][0], rev1 + rev2);
            update(dp[i + 1][1], dp[i][1], 2 - (rev1 + rev2));
            if ((a1 < b[pos2] && b[pos2] < b[pos1] && b[pos1] < a2) &&
                (b1 > a[pos2] && a[pos2] > a[pos1] && a[pos1] > b2)){
                update(dp[i + 1][1], dp[i][0], 2 - (rev1 + rev2));
                update(dp[i + 1][0], dp[i][1], rev1 + rev2);
            }
            a1 = a[pos1], b1 = b[pos1];
            a2 = a[pos2], b2 = b[pos2];
        }
    }
    int ans = std::min(dp[sz][0], dp[sz][1]);
    ans = ans == INF ? -1 : ans;
    printf("%d\n", ans);
    return 0;
}