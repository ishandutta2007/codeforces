#include <bits/stdc++.h>

const int N = 1000010;
using ll = long long;

struct frac{
    ll x, y;

    explicit frac(ll x = 0, ll y = 0):x(x), y(y){}

    frac operator +(const frac &f)const{
        return frac(x + f.x, y + f.y);
    }
    bool operator <=(const frac &f)const{
        return x * f.y <= y * f.x;
    }
};

int a[N];
int fa[N], left[N], right[N];
frac f[N];

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v){
        return;
    }
    left[v] = std::min(left[u], left[v]);
    right[v] = std::max(right[u], right[v]);
    f[v] = f[u] + f[v];
    fa[u] = v;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        f[i] = frac(a[i], 1);
        fa[i] = i;
        left[i] = right[i] = i;
    }
    std::set <int> set;
    for (int i = 0; i < n - 1; ++ i){
        set.insert(i);
    }
    while (!set.empty()){
        auto u = set.begin();
        int x = find(*u);
        set.erase(u);
        if (right[x] == n - 1){
            continue;
        }
        int t = find(right[x] + 1);
        if (f[t] <= f[x]){
            unite(x, t);
            x = find(x);
            set.insert(x);
            if (left[x] > 0){
                set.insert(find(left[x] - 1));
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        if (find(i) == i){
            ll x = f[i].x, y = f[i].y;
            for (int j = 0; j < y; ++ j){
                printf("%.15f\n", 1.0 * x / y);
            }
        }
    }
    return 0;
}