#include <bits/stdc++.h>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)

const int N = 2010;
const int MAX = 1 << 11;
const int moder = int(1e9) + 7;

int x[N], y[N], cx[N], cy[N], c[N];
std::map <int, int> map[N];
std::vector<int> vec[N], vecy[N];
int right[N];
int cnt[N];
int len[MAX << 1], seg[MAX << 1], min[MAX << 1], max[MAX << 1], lazy[MAX << 1];

void push(int sit){
    if (!lazy[sit]){
        return;
    }
    seg[ls(sit)] = 1ll * lazy[sit] * len[ls(sit)] % moder;
    seg[rs(sit)] = 1ll * lazy[sit] * len[rs(sit)] % moder;
    min[ls(sit)] = min[rs(sit)] = lazy[sit];
    max[ls(sit)] = max[rs(sit)] = lazy[sit];
    lazy[ls(sit)] = lazy[rs(sit)] = lazy[sit];
    lazy[sit] = 0;
}

void pull(int sit){
    seg[sit] = seg[ls(sit)] + seg[rs(sit)];
    seg[sit] -= seg[sit] >= moder ? moder : 0;
    len[sit] = len[ls(sit)] + len[rs(sit)];
    max[sit] = std::max(max[ls(sit)], max[rs(sit)]);
    min[sit] = std::min(min[ls(sit)], min[rs(sit)]);
}

void add(int sit, int l, int r, int ql, int qr, int value){
    if (ql > r || qr < l || value <= min[sit]){
        return;
    }
    if (ql <= l && qr >= r && value >= max[sit]){
        seg[sit] = 1ll * len[sit] * value % moder;
        lazy[sit] = min[sit] = max[sit] = value;
        return;
    }
    push(sit);
    int mid = (l + r) / 2;
    add(ls(sit), l, mid, ql, qr, value);
    add(rs(sit), mid + 1, r, ql, qr, value);
    pull(sit);
}

int query(int sit, int l, int r, int ql, int qr){
    if (ql > r || qr < l){
        return 0;
    }
    if (ql <= l && qr >= r){
        return seg[sit];
    }
    push(sit);
    int mid = (l + r) / 2;
    int ret = query(ls(sit), l, mid, ql, qr) + query(rs(sit), mid + 1, r, ql, qr);
    ret -= ret >= moder ? moder : 0;
    return ret;
}

void add(int l, int r, int value){
    if (l > r) return;
    add(1, 0, MAX - 1, l, r, value);
}

int query(int l, int r){
    return query(1, 0, MAX - 1, l, r);
}

void process(int n, int *x, int *cx, int &cntx){
    for (int i = 0; i < n; ++ i){
        cx[i] = x[i];
    }
    std::sort(cx, cx + n);
    cntx = std::unique(cx, cx + n) - cx;
    for (int i = 0; i < n; ++ i){
        x[i] = std::lower_bound(cx, cx + cntx, x[i]) - cx;
    }
}

int main(){
    int n, k, L;
    scanf("%d%d%d", &n, &k, &L);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d%d", &x[i], &y[i], &c[i]);
    }
    int cntx, cnty;
    process(n, x, cx, cntx);
    process(n, y, cy, cnty);
    for (int i = 0; i < n; ++ i){
        vec[x[i]].emplace_back(i);
        vecy[y[i]].emplace_back(i);
    }
    int base = 1ll * (cy[cnty - 1] + 1) * L % moder;
    int ans = 0;
    for (int i = 0; i < cntx; ++ i){
        for (int j = 0; j < N; ++ j){
            map[j].clear();
        }
        memset(cnt, 0, sizeof(cnt));
        memset(lazy, 0, sizeof(lazy));

        int sum = 0;
        for (int j = i; j < cntx; ++ j){
            for (auto u : vec[j]){
                ++ map[c[u]][y[u]];
            }
        }
        int ccnt = 0;
        for (int j = 0, u = 0; j < cnty; ++ j){
            while (u < cnty && ccnt < k){
                for (auto v : vecy[u]){
                    if (x[v] >= i){
                        ++ cnt[c[v]];
                        ccnt += cnt[c[v]] == 1;
                    }
                }
                ++ u;
            }
            right[j] = ccnt < k ? u : u - 1;
            for (auto v : vecy[j]){
                if (x[v] >= i){
                    ccnt -= cnt[c[v]] == 1;
                    -- cnt[c[v]];
                }
            }
        }
        auto real_pos = [&](int fake_pos){
            return fake_pos == cnty ? L : cy[fake_pos];
        };
        for (int j = 0; j < cnty; ++ j){
            len[j + MAX] = cy[j] - (j ? cy[j - 1] : -1);
            max[j + MAX] = min[j + MAX] = real_pos(right[j]);
            seg[j + MAX] = 1ll * len[j + MAX] * max[j + MAX] % moder;
        }
        for (int j = MAX - 1; j; -- j){
            pull(j);
        }
        sum = (sum + 1ll * (L - cx[cntx - 1]) * (base - query(0, cnty - 1))) % moder;
        for (int j = cntx - 1; j > i; -- j){
            for (auto u : vec[j]){
                auto v = map[c[u]].find(y[u]);
                if (v -> second >= 2){
                    -- v -> second;
                    continue;
                }
                v = map[c[u]].erase(v);
                int l;
                if (v == map[c[u]].begin()){
                    l = 0;
                }
                else{
                    l = std::prev(v) -> first + 1;
                }
                add(l, y[u], real_pos(v == map[c[u]].end() ? cnty : v -> first));
            }
            sum = (sum + 1ll * (cx[j] - cx[j - 1]) * (base - query(0, cnty - 1))) % moder;
        }
        ans = (ans + 1ll * sum * (cx[i] - (i ? cx[i - 1] : -1))) % moder;
    }
    ans += ans < 0 ? moder : 0;
    printf("%d\n", ans);
    return 0;
}