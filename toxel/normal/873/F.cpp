#include <bits/stdc++.h>

const int N = 1000010;
using ll = long long;

char s[N];
int sa[N], id[N], rk[N], oldrk[N << 1], tmp[N], cnt[N], height[N];

void get_sa(char *s, int *sa){
    int n = strlen(s + 1), m = 300;
    for (int i = 1; i <= n; ++ i) ++ cnt[rk[i] = s[i]];
    for (int i = 1; i <= m; ++ i) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; -- i) sa[cnt[s[i]] --] = i;
    if (n == 1) rk[1] = 1;
    auto equal = [&](int x, int y, int w){return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];};
    for (int w = 1, p; w < n; w <<= 1, m = p){
        p = 0;
        for (int i = n; i > n - w; -- i) id[++ p] = i;
        for (int i = 1; i <= n; ++ i){
            if (sa[i] > w) id[++ p] = sa[i] - w;
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++ i) ++ cnt[tmp[i] = rk[id[i]]];
        for (int i = 1; i <= m; ++ i) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; -- i) sa[cnt[tmp[i]] --] = id[i];
        memcpy(oldrk, rk, sizeof(rk));
        p = 0;
        for (int i = 1; i <= n; ++ i){
            rk[sa[i]] = equal(sa[i - 1], sa[i], w) ? p : ++ p;
        }
    }
    for (int i = 1, p = 0; i <= n; ++ i){
        if (p) -- p;
        while (s[i + p] == s[sa[rk[i] - 1] + p]) ++ p;
        height[rk[i]] = p;
    }
}

void init(){
    memset(cnt, 0, sizeof(cnt));
    memset(rk, 0, sizeof(rk));
}

char t[N];
int left[N], right[N];
int pre[N];

int main(){
    int n;
    scanf("%d%s%s", &n, s + 1, t + 1);
    std::reverse(s + 1, s + n + 1);
    std::reverse(t + 1, t + n + 1);
    for (int i = 1; i <= n; ++ i){
        t[i] ^= 1;
    }
    get_sa(s, sa);
    for (int i = 1; i <= n; ++ i){
        pre[i] = pre[i - 1] + t[sa[i]] - '0';
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++ i){
        if (t[i] == '1'){
            ans = std::max(ans, ll(n - i + 1));
        }
    }
    height[1] = height[n + 1] = -1;
    std::vector<int> stack;
    for (int i = 1; i <= n + 1; ++ i){
        while (!stack.empty() && height[stack.back()] > height[i]){
            right[stack.back()] = i;
            stack.pop_back();
        }
        if (!stack.empty()){
            left[i] = stack.back();
        }
        stack.emplace_back(i);
    }
    for (int i = 2; i <= n; ++ i){
        int num = pre[right[i] - 1] - pre[left[i] - 1];
        ans = std::max(ans, 1ll * num * height[i]);
    }
    printf("%lld\n", ans);
    return 0;
}