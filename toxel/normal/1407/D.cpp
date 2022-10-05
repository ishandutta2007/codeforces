#include <bits/stdc++.h>

const int N = 300010;
const int MAX = 1 << 19;
using pii = std::pair <int, int>;

struct Seg{
    int seg[MAX << 1];

    void add(int sit, int value){
        seg[sit += MAX] = value;
        for (sit >>= 1; sit; sit >>= 1){
            seg[sit] = std::min(seg[sit << 1], seg[sit << 1 | 1]);
        }
    }

    int query(int l, int r){
        if (l == 0){
            ++ l;
        }
        int ret = INT_MAX;
        for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
            if (l & 1) ret = std::min(ret, seg[l ++]);
            if (r & 1) ret = std::min(ret, seg[-- r]);
        }
        return ret;
    }
};

int h[N];
int dp[N];
int left1[N], left2[N];
// 1 >=, 2 <=
Seg seg1, seg2;

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &h[i]);
    }
    std::vector<int> stack1, stack2;
    for (int i = 1; i <= n; ++ i){
        while (!stack1.empty() && h[stack1.back()] < h[i]){
            stack1.pop_back();
        }
        while (!stack2.empty() && h[stack2.back()] > h[i]){
            stack2.pop_back();
        }
        if (!stack1.empty()){
            left1[i] = stack1.back();
        }
        if (!stack2.empty()){
            left2[i] = stack2.back();
        }
        stack1.emplace_back(i);
        stack2.emplace_back(i);
    }
    std::set <pii> set1, set2;
    for (int i = 1; i <= n; ++ i){
        if (i > 1){
            dp[i] = std::min(seg1.query(left1[i], i - 1), seg2.query(left2[i], i - 1)) + 1;
        }
        auto u = set1.begin();
        while (u != set1.end() && u -> first <= h[i]){
            seg1.add(u -> second, INT_MAX);
            u = set1.erase(u);
        }
        while (!set2.empty()){
            u = std::prev(set2.end());
            if (u -> first >= h[i]){
                seg2.add(u -> second, INT_MAX);
                set2.erase(u);
            }
            else{
                break;
            }
        }
        set1.insert({h[i], i});
        set2.insert({h[i], i});
        seg1.add(i, dp[i]);
        seg2.add(i, dp[i]);
    }
    printf("%d\n", dp[n]);
    return 0;
}