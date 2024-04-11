#include <bits/stdc++.h>

const int N = 500010;
using ll = long long;
using pii = std::pair <ll, ll>;
inline ll sqr(int x){return 1ll * x * x;}

struct Line{
    ll k, b, left;

    explicit Line(ll k = 0, ll b = 0, ll left = 0):k(k), b(b), left(left){}
};

ll divide(ll a, ll b){
    return a / b - (a % b && ((a > 0) ^ (b > 0)));
}

ll divideup(ll a, ll b){
    return divide(a, b) + (a % b != 0);
}

std::vector <int> e[N];
int sz[N];
ll dp[N];

void dfs(int u, int fa){
    sz[u] = 1;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void calcdp(int u, int fa){
    dp[u] = LLONG_MAX;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        calcdp(v, u);
        dp[u] = std::min(dp[u], dp[v] + 1ll * sqr(sz[u] - sz[v]));
    }
    if (dp[u] == LLONG_MAX){
        dp[u] = 1;
    }
}

ll ans = LLONG_MAX;
int n;

void solve(int u, int fa){
    std::vector <int> todo;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        solve(v, u);
        todo.push_back(v);
    }
    std::sort(todo.begin(), todo.end(), [&](const int &p1, const int &p2){
        return sz[p1] < sz[p2];
    });
    std::vector <Line> stack;
    int cur = 0;
    for (auto v : todo){
        if (!stack.empty()){
            int x = n - sz[v];
            cur = std::min(cur, (int) stack.size() - 1);
            while (x < stack[cur].left){
                -- cur;
            }
            while (cur + 1 < (int) stack.size() && x >= stack[cur + 1].left){
                ++ cur;
            }
            ll value = stack[cur].k * x + stack[cur].b + sqr(n - sz[v]) + dp[v];
            ans = std::min(ans, value);
        }
        Line nl(-2 * sz[v], sqr(sz[v]) + dp[v]);
        while (!stack.empty()){
            Line l = stack.back();
            if (l.k == nl.k){
                if (l.b >= nl.b){
                    stack.pop_back();
                }
                else{
                    break;
                }
            }
            else{
                ll cross = divideup(l.b - nl.b, nl.k - l.k);
                if (cross <= l.left){
                    stack.pop_back();
                }
                else{
                    nl.left = cross;
                    stack.push_back(nl);
                    break;
                }
            }
        }
        if (stack.empty()){
            nl.left = LLONG_MIN;
            stack.push_back(nl);
        }
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (n == 2){
        puts("2");
        return 0;
    }
    int root = -1;
    for (int i = 1; i <= n; ++ i){
        if ((int) e[i].size() >= 2){
            root = i;
            break;
        }
    }
    dfs(root, 0);
    calcdp(root, 0);
    solve(root, 0);
    printf("%lld\n", 1ll * n * (n - 1) - (ans - n) / 2);
    return 0;
}