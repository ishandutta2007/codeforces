#include<bits/stdc++.h>

std::map <int, int> fa;
std::map <int, int> value;

int find(int u){
    if (fa[u] == u){
        return u;
    }
    int prefa = fa[u];
    fa[u] = find(fa[u]);
    value[u] ^= value[prefa];
    return fa[u];
}

void unite(int u, int v, int val){
    int preu = u, prev = v;
    u = find(u), v = find(v);
    fa[u] = v;
    value[u] = value[preu] ^ value[prev] ^ val;
}

int main(){
    int q;
    scanf("%d", &q);
    int last = 0;
    while (q --){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            l ^= last, r ^= last, x ^= last;
            if (l > r){
                std::swap(l, r);
            }
            ++ r;
            if (!fa.count(l)){fa[l] = l; value[l] = 0;}
            if (!fa.count(r)){fa[r] = r; value[r] = 0;}
            int fau = find(l), fav = find(r);
            if (fau != fav){
                unite(l, r, x);
            }
        }
        else{
            int l, r;
            scanf("%d%d", &l, &r);
            l ^= last, r ^= last;
            if (l > r){
                std::swap(l, r);
            }
            ++ r;
            if (!fa.count(l) || !fa.count(r)){
                puts("-1");
                last = 1;
                continue;
            }
            int fau = find(l), fav = find(r);
            if (fau != fav){
                puts("-1");
                last = 1;
                continue;
            }
            int ans = value[l] ^ value[r];
            printf("%d\n", ans);
            last = ans;
        }
    }
    return 0;
}