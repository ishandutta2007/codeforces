//
// Created by  on 2022/2/6.
//

//
// Created by  on 2022/1/6.
//

#ifndef WORKSPACE_TEMPLATE_H
#define WORKSPACE_TEMPLATE_H

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define puts dont_use_puts
#define endl dont_use_endl

using ll = int64_t;
using i128 = __int128_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;
using piiii = std::tuple <int, int, int, int>;
using pll = std::pair <ll, ll>;
using plll = std::tuple <ll, ll, ll>;
using pllll = std::tuple <ll, ll, ll, ll>;

//
// Created by  on 2022/2/6.
//

#ifndef WORKSPACE_SEGMENTZKW_H
#define WORKSPACE_SEGMENTZKW_H

#include <bits/stdc++.h>

namespace Seg{
    using T = pll;

    class Seg{
#define ls(u) ((u) << 1)
#define rs(u) (((u) << 1) | 1)
    public:
        int maximum;
        std::vector <T> seg;

        explicit Seg(int range):seg(){
            maximum = 1;
            while (maximum <= range + 10){
                maximum <<= 1;
            }
            seg.resize(maximum << 1);
            init();
        }

        void init(){
            for (int i = maximum; i < maximum + maximum; ++ i){
                seg[i] = T{};
            }
            for (int i = maximum - 1; i; -- i){
                pull(i);
            }
        }

        T merge(const T &t1, const T &t2){
            auto [u1, v1] = t1;
            auto [u2, v2] = t2;
            return {u1 + u2, v1 + v2};
        }

        void pull(int sit){
            seg[sit] = merge(seg[ls(sit)], seg[rs(sit)]);
        }

        void add(int sit, T value){
            sit += maximum;
            seg[sit] = merge(seg[sit], value);
            for (sit >>= 1; sit; sit >>= 1){
                pull(sit);
            }
        }

        T query(int sit, int l, int r, int ql, int qr){
            if (ql > r || qr < l){
                return {0, 0};
            }
            if (ql <= l && qr >= r){
                return seg[sit];
            }
            int mid = (l + r) / 2;
            return merge(query(ls(sit), l, mid, ql, qr),
                            query(rs(sit), mid + 1, r, ql, qr));
        }

        pll query(int l, int r){
            return query(1, 0, maximum - 1, l, r);
        }

        int query_first(int sit, int l, int r, int ql, int qr, ll val){
            if (ql > r || qr < l){
                return -1;
            }
            if (seg[sit].first < val){
                return -1;
            }
            if (l == r){
                return l;
            }
            int mid = (l + r) / 2;
            int ans = query_first(ls(sit), l, mid, ql, qr, val);
            if (ans != -1) return ans;
            // sometimes you need use new_val in right query
            return query_first(rs(sit), mid + 1, r, ql, qr, val - query(ls(sit), l, mid, std::max(l, ql), std::min(mid, qr)).first);
        }

        int query_first(int ql, int qr, ll val){
            return query_first(1, 0, maximum - 1, ql, qr, val);
        }
    };
}

#endif //WORKSPACE_SEGMENTZKW_H

//
// Created by  on 2022/1/31.
//

#ifndef WORKSPACE_SEGMENTRANGE_H
#define WORKSPACE_SEGMENTRANGE_H

#include <bits/stdc++.h>

namespace SegRange{
    using T = ll;

    class Node{
    public:
        pll value;
        T lazy;

        Node():value(), lazy(){}
        Node(pll value, T lazy):value(value), lazy(lazy){}
    };

    class Seg{
#define ls(u) ((u) << 1)
#define rs(u) (((u) << 1) | 1)
// #define OPERATE +
    public:
        int maximum;
        std::vector <Node> seg;

        explicit Seg(int range):seg(){
            maximum = 1;
            while (maximum <= range + 10){
                maximum <<= 1;
            }
            seg.resize(maximum << 1);
            init();
        }

        void init(){
            // for (int i = maximum; i < maximum + maximum; ++ i){
            //     seg[i] = Node();
            // }
            for (int i = maximum - 1; i; -- i){
                pull(i);
            }
        }

        void update(int sit, T value){
            seg[sit].value.first += value;
            seg[sit].lazy += value;
        }

        void push(int sit){
            if (seg[sit].lazy == 0){
                return;
            }
            update(ls(sit), seg[sit].lazy);
            update(rs(sit), seg[sit].lazy);
            seg[sit].lazy = 0;
        }

        void pull(int sit){
            seg[sit].value = std::min(seg[ls(sit)].value, seg[rs(sit)].value);
        }

        void add(int sit, int l, int r, int ql, int qr, T value){
            if (ql > r || qr < l){
                return;
            }
            if (ql <= l && qr >= r){
                update(sit, value);
                return;
            }
            push(sit);
            int mid = (l + r) / 2;
            add(ls(sit), l, mid, ql, qr, value);
            add(rs(sit), mid + 1, r, ql, qr, value);
            pull(sit);
        }

        void add(int l, int r, T value){
            add(1, 0, maximum - 1, l, r, value);
        }

        pll query(int sit, int l, int r, int ql, int qr){
            if (ql > r || qr < l){
                return {LLONG_MAX, LLONG_MAX};
            }
            if (ql <= l && qr >= r){
                return seg[sit].value;
            }
            push(sit);
            int mid = (l + r) / 2;
            return std::min(query(ls(sit), l, mid, ql, qr),
                    query(rs(sit), mid + 1, r, ql, qr));
        }

        pll query(int l, int r){
            return query(1, 0, maximum - 1, l, r);
        }

        int query_first(int sit, int l, int r, int ql, int qr, T val){
            if (ql > r || qr < l){
                return -1;
            }
            if (seg[sit].value.first > val){
                return -1;
            }
            if (l == r){
                return l;
            }
            push(sit);
            int mid = (l + r) / 2;
            int ans = query_first(ls(sit), l, mid, ql, qr, val);
            if (ans != -1) return ans;
            // sometimes you need use new_val in right query
            return query_first(rs(sit), mid + 1, r, ql, qr, val);
        }

        int query_first(int ql, int qr, T val){
            return query_first(1, 0, maximum - 1, ql, qr, val);
        }
    };
}

#endif //WORKSPACE_SEGMENTRANGE_H

void solve(){
    int n, q;
    std::cin >> n >> q;
    std::vector <int> a(n + 1), w(n + 1), v(n + 1), ids;
    for (int i = 1; i <= n; ++ i){
        std::cin >> a[i] >> w[i] >> v[i];
        ids.emplace_back(i);
    }
    std::sort(ids.begin(), ids.end(), [&](const int &id1, const int &id2){
        if (v[id1] != v[id2]){
            return v[id1] > v[id2];
        }
        return w[id1] < w[id2];
    });
    std::vector <int> inv(n + 1);
    for (int i = 0; i < n; ++ i){
        inv[ids[i]] = i + 1;
    }
    std::vector <pii> vec(n + 1);
    std::vector <ll> count(n + 1);
    for (int i = 1; i <= n; ++ i){
        int pos = inv[i];
        vec[pos] = {w[i], v[i]};
        count[pos] = a[i];
    }
    const int BIT = 20;
    std::vector <Seg::Seg> seg(BIT, Seg::Seg(n + 1));
    std::vector <SegRange::Seg> seg1(BIT, SegRange::Seg(n + 1));
    const ll INF = 1e18;
    for (auto &u : seg1){
        for (int i = 0; i < u.maximum; ++ i){
            u.seg[i + u.maximum].value = {INF, i};
        }
        u.init();
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < BIT; ++ j){
            if (count[i] > 0 && vec[i].first >= (1ll << j) && vec[i].first < (1ll << (j + 1))){
                seg1[j].add(i, i, -INF + vec[i].first);
            }
        }
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < BIT; ++ j){
            if (vec[i].first < (1ll << j)){
                seg[j].add(i, {1ll * count[i] * vec[i].first, 1ll * count[i] * vec[i].second});
                seg1[j].add(i + 1, n, 1ll * count[i] * vec[i].first);
            }
        }
    }
    while (q --){
        int type;
        std::cin >> type;
        if (type == 1){
            int k, d;
            std::cin >> k >> d;
            d = inv[d];
            count[d] += k;
            for (int i = 0; i < BIT; ++ i){
                if (vec[d].first < (1ll << i)){
                    seg[i].add(d, {1ll * k * vec[d].first, 1ll * k * vec[d].second});
                    seg1[i].add(d + 1, n, 1ll * k * vec[d].first);
                }
                if (count[d] > 0 && vec[d].first >= (1ll << i) && vec[d].first < (1ll << (i + 1))){
                    pll cur = seg1[i].query(d, d);
                    ll target = vec[d].first + seg[i].query(1, d - 1).first;
                    seg1[i].add(d, d, target - cur.first);
                }
            }
        }
        else if (type == 2){
            int k, d;
            std::cin >> k >> d;
            d = inv[d];
            count[d] -= k;
            for (int i = 0; i < BIT; ++ i){
                if (vec[d].first < (1ll << i)){
                    seg[i].add(d, {-1ll * k * vec[d].first, -1ll * k * vec[d].second});
                    seg1[i].add(d + 1, n, -1ll * k * vec[d].first);
                }
                if (count[d] == 0 && vec[d].first >= (1ll << i) && vec[d].first < (1ll << (i + 1))){
                    pll cur = seg1[i].query(d, d);
                    ll target = INF;
                    seg1[i].add(d, d, target - cur.first);
                }
            }
        }
        else if (type == 3){
            ll c;
            std::cin >> c;
            int cur = 1;
            ll ans = 0;
            for (int i = BIT - 1; i >= 0 && cur <= n; -- i){
                int pos = seg[i].query_first(cur, n, c - (1ll << i) + 1);
                if (pos == -1){
                    pos = n + 1;
                }
                pll p = seg[i].query(cur, pos - 1);
                ans += p.second;
                c -= p.first;
                if (pos <= n){
                    ll num = std::min(count[pos], c / vec[pos].first);
                    ans += num * vec[pos].second;
                    c -= num * vec[pos].first;
                    cur = pos + 1;
                    assert(c < (1ll << i));
                }
                else{
                    break;
                }
                if (i > 0 && cur <= n){
                    pos = seg1[i - 1].query_first(cur, n, c + seg[i - 1].query(1, cur - 1).first);
                    if (pos != -1){
                        p = seg[i - 1].query(cur, pos - 1);
                        ans += p.second;
                        c -= p.first;
                        ans += vec[pos].second;
                        c -= vec[pos].first;
                        cur = pos + 1;
                    }
                }
            }
            std::cout << ans << '\n';
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    while (test --){
        solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H