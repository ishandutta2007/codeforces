#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair <int, int> pii;
typedef std::pair <pii, ll> piii;
const int N = 1000010;
const ll INF = 1e10;

ll dp[N];
piii p[N];

struct line{
    int k;
    ll s, b;

    ll inter(line l){
        return (b - l.b) / (l.k - k);
    }

    bool operator < (const line &l)const{
        return s > l.s;
    }
};

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        int x, y;
        ll a;
        scanf("%d%d%lld", &x, &y, &a);
        //x = i + 1, y = 1000000 - i, a = 0;
        p[i] = {{x, y}, a};
    }
    std::sort(p, p + n);
    std::vector <line> stack;
    for (int i = 0; i < n; ++ i){
        int x = p[i].first.first, y = p[i].first.second;
        ll a = p[i].second;
        if (i){
            line query = {0, y, 0};
            int sit = std::upper_bound(stack.begin(), stack.end(), query) - stack.begin() - 1;
            line l = stack[sit];
            dp[i] = 1ll * l.k * y + l.b + 1ll * x * y - a;
        }
        dp[i] = std::max(dp[i], 1ll * x * y - a);
        line nl = {-x, 0, dp[i]};
        while (!stack.empty()){
            ll sit = nl.inter(stack.back());
            sit = std::min(INF, sit);
            if (sit >= stack.back().s){
                stack.pop_back();
            }
            else{
                nl.s = sit;
                stack.push_back(nl);
                break;
            }
        }
        if (stack.empty()){
            nl.s = INF;
            stack.push_back(nl);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++ i){
        ans = std::max(ans, dp[i]);
    }
    printf("%lld\n", ans);
    return 0;
}