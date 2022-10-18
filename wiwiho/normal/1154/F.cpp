#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <functional>
#include <string>
#include <string.h>

//#define TEST

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<long long> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    n = k;

    long long cost[n + 1];
    cost[0] = 0;
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        cost[i + 1] = sum;
    }

    std::vector<std::pair<int, int>> offer(m + 1);
    offer[0].first = 1;
    offer[0].second = 0;
    for(int i = 1; i < m + 1; i++){
        std::cin >> offer[i].first;
        std::cin >> offer[i].second;
    }

    long long dp[n + 1];
    dp[0] = 0;
    for(int i = 1; i < n + 1; i++){
        dp[i] = -1;
    }

    long long ans = 10000000000;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m + 1; j++){
            if(i + offer[j].first > n){
                continue;
            }
            long long c = dp[i] + cost[i + offer[j].first] - cost[i + offer[j].second];
            if(dp[i + offer[j].first] == -1){
                dp[i + offer[j].first] = c;
            }
            else if(c < dp[i + offer[j].first]){
                dp[i + offer[j].first] = c;
            }
        }
    }

    std::cout << dp[k] << "\n";

    return 0;
}