#include<bits/stdc++.h>

const int N = 200010;

int fa[N];
int a[N];

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    int _u = find(u), _v = find(v);
    if (_u == _v) return;
    fa[_u] = _v;
}

int sz[N];

void walk(int &x){
    for (int i = 0, sz = ::sz[x] << 1; i < sz; ++ i){
        x = a[x];
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        fa[i] = i;
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        unite(i, a[i]);
    }
    for (int i = 1; i <= n; ++ i){
        ++ sz[find(i)];
    }
    int cnt = 0;
    int hasloop = 0;
    for (int i = 1; i <= n; ++ i){
        cnt += sz[i] > 0;
        if (a[i] == i){
            hasloop = i;
        }
    }
    if (hasloop){
        -- cnt;
    }
    else{
        for (int i = 1; i <= n; ++ i){
            if (sz[i]){
                int x = i;
                walk(x);
                a[x] = x;
                hasloop = x;
                break;
            }
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; ++ i){
        if (sz[i] && find(i) != find(hasloop)){
            int x = i;
            walk(x);
            a[x] = hasloop;
        }
    }
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", a[i], " \n"[i == n]);
    }
    return 0;
}