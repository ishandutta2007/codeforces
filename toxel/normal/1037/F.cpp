#include<bits/stdc++.h>

const int N = 1000010;
const int moder = 1e9 + 7;

int a[N];
int left[N], right[N];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    -- k;
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    a[0] = INT_MAX;
    a[n + 1] = INT_MAX;
    std::stack <int> stack;
    for (int i = 0; i <= n + 1; ++ i){
        while (!stack.empty() && a[stack.top()] < a[i]){
            right[stack.top()] = i;
            stack.pop();
        }
        if (!stack.empty()){
            left[i] = stack.top();
        }
        stack.push(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        int x = i - left[i];
        int y = right[i] - i;
        int tmp = 0;
        tmp = (tmp + 1ll * x * (y / k) % moder * a[i]) % moder;
        tmp = (tmp + 1ll * (x / k) * y % moder * a[i]) % moder;
        tmp = (tmp - 1ll * (x / k) * (y / k) % moder * k % moder * a[i]) % moder;
        tmp += tmp < 0 ? moder : 0;
        ans += tmp;
        ans -= ans >= moder ? moder : 0;
        int left1 = 0, right1 = x % k - 1;
        int left2 = 0, right2 = y % k - 1;
        int cnt = right1 >= 0 && right2 >= 0;
        int tmp1 = k - right2, tmp2 = k - left2;
        int l = std::max(left1, tmp1), r = std::min(right1, tmp2);
        if (l <= r){
            cnt += r - l + 1;
        }
        ans = (ans + 1ll * cnt * a[i]) % moder;
        ans -= a[i];
        ans += ans < 0 ? moder : 0;
    }
    printf("%d\n", ans);
    return 0;
}