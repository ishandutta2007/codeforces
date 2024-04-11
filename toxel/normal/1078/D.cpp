#include<bits/stdc++.h>

const int N = 100010;
const int BIT = 17;
const int MAX = 1 << BIT;
typedef std::pair <int, int> pii;

int n;
int r[N];
pii seg[BIT][MAX << 1];

pii max(pii p1, pii p2){
    return {std::min(p1.first, p2.first), std::max(p1.second, p2.second)};
}

void add(pii *seg, int sit, pii value){
    seg[sit += MAX] = value;
    for (sit >>= 1; sit; sit >>= 1){
        seg[sit] = max(seg[sit << 1], seg[sit << 1 | 1]);
    }
}

pii query(pii *seg, int l, int r){
    pii ret = {INT_MAX, INT_MIN};
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) ret = max(ret, seg[l ++]);
        if (r & 1) ret = max(ret, seg[-- r]);
    }
    return ret;
}

pii query2(pii *seg, int l, int r){
    if (r - l + 1 >= n){
        return query(seg, 0, n - 1);
    }
    pii ret = query(seg, std::max(l, 0), std::min(r, n - 1));
    if (r >= n){
        pii p = query(seg, 0, r - n);
        p.first += n, p.second += n;
        ret = max(ret, p);
    }
    if (l < 0){
        pii p = query(seg, l + n, n - 1);
        p.first -= n, p.second -= n;
        ret = max(ret, p);
    }
    return ret;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &r[i]);
    }
    if (n == 1){
        puts("0");
        return 0;
    }
    for (int i = 0; i < n; ++ i){
        add(seg[0], i, {i - r[i], i + r[i]});
    }
    for (int j = 1; j < BIT; ++ j){
        for (int i = 0; i < n; ++ i){
            pii p = seg[j - 1][i + MAX];
            add(seg[j], i, query2(seg[j - 1], p.first, p.second));
        }
    }
    for (int i = 0; i < n; ++ i){
        int l = i, r = i;
        int ans = 0;
        for (int j = BIT - 1; j >= 0; -- j){
            pii p = query2(seg[j], l, r);
            if (p.second - p.first + 1 < n){
                ans += 1 << j;
                r = p.second;
                l = p.first;
            }
        }
        printf("%d%c", ans + 1, " \n"[i == n - 1]);
    }
    return 0;
}