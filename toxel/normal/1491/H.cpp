#include <bits/stdc++.h>

const int N = 100010;
const int BLOCK_SZ = 330;

int a[N], f[N], offset[BLOCK_SZ];
int l[BLOCK_SZ], r[BLOCK_SZ], blockid[N];
int tmp1[BLOCK_SZ], tmp2[BLOCK_SZ];
bool finalized[BLOCK_SZ];

int prev(int u){
    return std::max(1, a[u] + offset[blockid[u]]);
}

void rebuild(int block){
    if (finalized[block]){
        return;
    }
    finalized[block] = true;
    for (int i = l[block]; i <= r[block]; ++ i){
        if (prev(i) < l[block]){
            f[i] = i;
        }
        else{
            f[i] = f[prev(i)];
            finalized[block] = false;
        }
    }
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    int blockcnt = 0;
    for (int left = 2, right; left <= n; left = right + 1){
        right = left + BLOCK_SZ - 1;
        right = std::min(n, right);
        for (int i = left; i <= right; ++ i){
            blockid[i] = blockcnt;
        }
        l[blockcnt] = left;
        r[blockcnt] = right;
        ++ blockcnt;
    }
    for (int i = 0; i < blockcnt; ++ i){
        rebuild(i);
    }
    while (q --){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int left, right, x;
            scanf("%d%d%d", &left, &right, &x);
            int lb = blockid[left], rb = blockid[right];
            auto process = [&](int id){
                for (int i = l[id]; i <= r[id]; ++ i){
                    a[i] += offset[id];
                    if (left <= i && i <= right){
                        a[i] -= x;
                    }
                    a[i] = std::max(1, a[i]);
                }
                offset[id] = 0;
            };
            if (lb == rb){
                process(lb);
            }
            else{
                process(lb);
                process(rb);
                for (int i = lb + 1; i < rb; ++ i){
                    offset[i] -= x;
                }
            }
            for (int i = lb; i <= rb; ++ i){
                rebuild(i);
            }
        }
        else{
            int u, v;
            scanf("%d%d", &u, &v);
            while (u != v && u > 1 && v > 1){
                int lb = blockid[u], rb = blockid[v];
                if (lb < rb){
                    v = prev(f[v]);
                }
                else if (lb > rb){
                    u = prev(f[u]);
                }
                else{
                    if (f[u] != f[v]){
                        u = prev(f[u]);
                        v = prev(f[v]);
                    }
                    else{
                        int cnt1 = 0, cnt2 = 0;
                        while (u != f[u]){
                            tmp1[cnt1 ++] = u;
                            u = prev(u);
                        }
                        tmp1[cnt1 ++] = u;
                        while (v != f[v]){
                            tmp2[cnt2 ++] = v;
                            v = prev(v);
                        }
                        tmp2[cnt2 ++] = v;
                        for (int i = 0; i < cnt1 && i < cnt2; ++ i){
                            if (tmp1[cnt1 - i - 1] == tmp2[cnt2 - i - 1]){
                                u = v = tmp1[cnt1 - i - 1];
                            }
                            else{
                                break;
                            }
                        }
                    }
                }
            }
            if (u == 1 || v == 1){
                printf("%d\n", 1);
            }
            else{
                printf("%d\n", u);
            }
        }
    }
    return 0;
}