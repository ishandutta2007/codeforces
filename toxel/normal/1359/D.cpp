#include <bits/stdc++.h>

const int N = 100010;
const int MAX = 1 << 17;

int a[N], pre[N], left[N], right[N];
int seg[MAX << 1], seg1[MAX << 1];

int query(int l, int r){
    int ret = INT_MIN;
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) ret = std::max(seg[l ++], ret);
        if (r & 1) ret = std::max(seg[-- r], ret);
    }
    return ret;
}

int query1(int l, int r){
    int ret = INT_MAX;
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) ret = std::min(seg1[l ++], ret);
        if (r & 1) ret = std::min(seg1[-- r], ret);
    }
    return ret;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        pre[i] = pre[i - 1] + a[i];
    }
    a[0] = a[n + 1] = INT_MAX;
    std::vector<int> stack;
    for (int i = 0; i <= n + 1; ++ i){
        while (!stack.empty() && a[stack.back()] < a[i]){
            right[stack.back()] = i;
            stack.pop_back();
        }
        if (!stack.empty()){
            left[i] = stack.back();
        }
        stack.push_back(i);
    }
    for (int i = 0; i < N; ++ i){
        seg[i + MAX] = pre[i];
        seg1[i + MAX] = pre[i];
    }
    for (int i = MAX - 1; i; -- i){
        seg[i] = std::max(seg[i << 1], seg[i << 1 | 1]);
        seg1[i] = std::min(seg1[i << 1], seg1[i << 1 | 1]);
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; ++ i){
        int x = query(i, right[i] - 1) - query1(left[i], i - 1) - a[i];
        ans = std::max(ans, x);
    }
    printf("%d\n", ans);
    return 0;
}