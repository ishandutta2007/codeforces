#include<bits/stdc++.h>

const int N = 100010;
typedef long long ll;

int a[N], dif[N];
int left[N], right[N];

ll solve(int *a, int n){
    std::stack <int> stack;
    int tmp1 = a[0], tmp2 = a[n + 1];
    a[0] = INT_MAX;
    a[n + 1] = INT_MAX;
    for (int i = 0; i <= n + 1; ++ i){
        while (!stack.empty() && a[stack.top()] <= a[i]){
            right[stack.top()] = i;
            stack.pop();
        }
        if (!stack.empty()) left[i] = stack.top();
        stack.push(i);
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++ i){
        ans += 1ll * (right[i] - i) * (i - left[i]) * a[i];
    }
    a[0] = tmp1;
    a[n + 1] = tmp2;
    return ans;
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 2; i <= n; ++ i){
        dif[i] = std::abs(a[i] - a[i - 1]);
    }
    while (q --){
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%lld\n", solve(dif + l, r - l));
    }
    return 0;
}