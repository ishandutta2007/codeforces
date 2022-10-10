#include <iostream>
#include <cstdio>
#include <vector>

int kadane(std::vector<int> a) {
    int sum = 0, mn = 0, ans = 0;
    for(auto v : a) {
        sum += v;
        ans = std::max(ans, sum - mn);
        mn = std::min(mn, sum);
    }
    return ans;
}

const int ms = 500500;
std::vector<int> p[ms];
int sum[ms];

int solve(std::vector<int> pos) {
    std::vector<int> v;
    for(int i = 0; i + 1 < (int) pos.size(); i++) {
        v.push_back(1);
        v.push_back(-sum[pos[i+1]] + sum[pos[i]]);
    }
    v.push_back(1);
    return kadane(v);
}

int main() {
    int n, c;
    std::cin >> n >> c;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        sum[i+1] = sum[i];
        if(x == c) {
            sum[i+1]++;
        } else {
            p[x].push_back(i);
        }
    }
    int ans = sum[n];
    for(int i = 0; i < ms; i++) {
        if(!p[i].empty()) {
            ans = std::max(ans, sum[n] + solve(p[i]));
        }
    }
    std::cout << ans << '\n';
}