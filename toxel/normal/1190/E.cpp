#include <bits/stdc++.h>

using pdd = std::pair <double, double>;
using pii = std::pair <int, int>;
using pddi = std::pair <pdd, int>;
const int N = 200010;
const int BIT = 20;
double sqr(double x){return x * x;}
const double PI = std::acos(-1.0);

int x[N], y[N];
int dp[N][BIT];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &x[i], &y[i]);
    }
    double min = 1e100;
    for (int i = 0; i < n; ++ i){
        if (x[i] == 0 && y[i] == 0){
            printf("%.15f\n", 0.0);
            return 0;
        }
        min = std::min(min, std::sqrt(sqr(x[i]) + sqr(y[i])));
    }
    double left = 0, right = min;
    for (int _ = 0; _ < 50; ++ _){
        double mid = (left + right) * 0.5;
        std::vector <pddi> vec;
        for (int i = 0; i < n; ++ i){
            double value = mid / std::sqrt(sqr(x[i]) + sqr(y[i]));
            double angle = std::atan2(y[i], x[i]);
            double diff = std::acos(std::min(std::max(-1.0, value), 1.0));
            double left = angle - diff, right = angle + diff;
            if (right >= 2 * PI){
                left -= 2 * PI, right -= 2 * PI;
            }
            if (right < 0){
                left += 2 * PI, right += 2 * PI;
            }
            vec.emplace_back(pdd{left, right}, i);
            if (left >= 0){
                left -= 2 * PI, right -= 2 * PI;
                vec.emplace_back(pdd{left, right}, i);
            }
        }
        std::sort(vec.begin(), vec.end());
        std::vector <bool> vis(n);
        std::vector <std::pair <pdd, int>> stack;
        for (auto u : vec){
            while (!stack.empty() && stack.back().first.second >= u.first.second){
                vis[stack.back().second] = true;
                stack.pop_back();
            }
            stack.push_back(u);
        }
        std::vector <pdd> vvec;
        for (auto u : stack){
            if (u.first.second >= 0 && !vis[u.second]){
                vvec.push_back(u.first);
            }
        }
        memset(dp, 0, sizeof(dp));
        int sz = vvec.size();
        for (int i = 0; i < sz; ++ i){
            vvec.emplace_back(vvec[i].first + 2 * PI, vvec[i].second + 2 * PI);
        }
        for (int i = 0, j = 0; i < 2 * sz; ++ i){
            while (j < 2 * sz && vvec[j].first <= vvec[i].second){
                ++ j;
            }
            dp[i][0] = j;
        }
        dp[2 * sz][0] = 2 * sz;
        for (int i = 1; i < BIT; ++ i){
            for (int j = 0; j <= 2 * sz; ++ j){
                dp[j][i] = dp[dp[j][i - 1]][i - 1];
            }
        }
        bool flag = false;
        for (int i = 0; i < sz; ++ i){
            int next = i;
            for (int j = BIT - 1; j >= 0; -- j){
                if (m >> j & 1){
                    next = dp[next][j];
                }
            }
            if (next >= i + sz){
                flag = true;
                break;
            }
        }
        if (flag){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    printf("%.15f\n", left);
    return 0;
}