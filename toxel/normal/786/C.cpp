#include <bits/stdc++.h>

const int N = 100010;
const int MAX = 1 << 17;
using pii = std::pair <int, int>;

std::vector <int> vec[N];
std::queue <int> pos[N];
int a[N], ans[N];
int seg[MAX << 1];

void add(int sit, int value){
    seg[sit += MAX] = value;
    for (sit >>= 1; sit; sit >>= 1){
        seg[sit] = seg[sit << 1] + seg[sit << 1 | 1];
    }
}

pii query(int sit, int l, int r, int ql, int qr, int value){
    if (ql > r || qr < l){
        return {-1, 0};
    }
    if (ql <= l && qr >= r && seg[sit] < value){
        return {-1, seg[sit]};
    }
    if (l == r){
        return {l, seg[sit]};
    }
    int mid = (l + r) / 2;
    pii ret = query(sit << 1, l, mid, ql, qr, value);
    if (ret.first != -1){
        return ret;
    }
    pii ret1 = query(sit << 1 | 1, mid + 1, r, ql, qr, value - ret.second);
    ret1.second += ret.second;
    return ret1;
}

pii query(int ql, int qr, int value){
    return query(1, 0, MAX - 1, ql, qr, value);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        pos[a[i]].push(i);
    }
    for (int i = 1; i <= n; ++ i){
        if (!pos[i].empty()){
            add(pos[i].front(), 1);
        }
        vec[0].push_back(i);
    }
    for (int i = 0; i < n; ++ i){
        for (auto u : vec[i]){
            ++ ans[u];
            pii p = query(i, n - 1, u + 1);
            if (p.first != -1){
                vec[p.first].push_back(u);
            }
        }
        pos[a[i]].pop();
        if (!pos[a[i]].empty()){
            add(pos[a[i]].front(), 1);
        }
    }
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}