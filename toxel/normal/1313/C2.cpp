#include <bits/stdc++.h>

using ll = long long;
const int N = 500010;

struct Event{
    int l, r, value;

    Event(int l = 0, int r = 0, int value = 0):l(l), r(r), value(value){}

    ll get(){
        return 1ll * (r - l + 1) * value;
    }
};

int a[N];
ll sum[N], ans[N];

void solve(int n){
    std::vector <Event> stack;
    ll tot = 0;
    for (int i = 0; i < n; ++ i){
        while (!stack.empty() && stack.back().value >= a[i]){
            tot -= stack.back().get();
            stack.pop_back();
        }
        stack.emplace_back(stack.empty() ? 0 : stack.back().r + 1, i, a[i]);
        tot += stack.back().get();
        ans[i] = tot;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    solve(n);
    memcpy(sum, ans, sizeof(ans));
    std::reverse(a, a + n);
    solve(n);
    int pos = -1;
    ll max = 0;
    std::reverse(a, a + n);
    for (int i = 0; i < n; ++ i){
        sum[i] += ans[n - 1 - i] - a[i];
        if (sum[i] > max){
            max = sum[i];
            pos = i;
        }
    }
    for (int i = pos - 1; i >= 0; -- i){
        a[i] = std::min(a[i], a[i + 1]);
    }
    for (int i = pos + 1; i < n; ++ i){
        a[i] = std::min(a[i], a[i - 1]);
    }
    for (int i = 0; i < n; ++ i){
        printf("%d%c", a[i], " \n"[i == n - 1]);
    }
    return 0;
}