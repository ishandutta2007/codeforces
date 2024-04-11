//
// Created by  on 2022/1/16.
//

//
// Created by  on 2022/1/6.
//

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define endl dont_use_endl

using ll = int64_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

#include <bits/stdc++.h>

namespace Seg{
    using T = ll;

    class Node{
    public:
        T value, coe[2];
        T lazy[2];

        Node():value(), coe(), lazy(){}
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
        }

        void init(){
            for (int i = maximum - 1; i; -- i){
                pull(i);
                for (int j = 0; j < 2; ++ j){
                    seg[i].coe[j] = seg[ls(i)].coe[j] + seg[rs(i)].coe[j];
                }
            }
        }

        void update(int sit, T value, int type){
            seg[sit].value += seg[sit].coe[type] * value;
            seg[sit].lazy[type] += value;
        }

        void push(int sit){
            for (int i = 0; i < 2; ++ i){
                if (seg[sit].lazy[i]){
                    update(ls(sit), seg[sit].lazy[i], i);
                    update(rs(sit), seg[sit].lazy[i], i);
                    seg[sit].lazy[i] = 0;
                }
            }
        }

        void pull(int sit){
            seg[sit].value = seg[ls(sit)].value + seg[rs(sit)].value;
        }

        void add(int sit, int l, int r, int ql, int qr, T value, int type){
            if (ql > r || qr < l){
                return;
            }
            if (ql <= l && qr >= r){
                update(sit, value, type);
                return;
            }
            push(sit);
            int mid = (l + r) / 2;
            add(ls(sit), l, mid, ql, qr, value, type);
            add(rs(sit), mid + 1, r, ql, qr, value, type);
            pull(sit);
        }

        void add(int l, int r, T value){
            add(1, 0, maximum - 1, l, r, value, 1);
            add(1, 0, maximum - 1, l, r, -value * (l - 1), 0);
        }

        T query(int sit, int l, int r, int ql, int qr){
            if (ql > r || qr < l){
                return 0;
            }
            if (ql <= l && qr >= r){
                return seg[sit].value;
            }
            push(sit);
            int mid = (l + r) / 2;
            return query(ls(sit), l, mid, ql, qr) +
                   query(rs(sit), mid + 1, r, ql, qr);
        }

        T query(int l, int r){
            return query(1, 0, maximum - 1, l, r);
        }
    };
}

namespace Seg1{
    using T = ll;

    class Node{
    public:
        T value;
        T lazy;

        Node():value(), lazy(){}
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
        }

        void init(){
            for (int i = maximum - 1; i; -- i){
                pull(i);
            }
        }

        void update(int sit, T value){
            seg[sit].value += value;
            seg[sit].lazy += value;
        }

        void push(int sit){
            if (seg[sit].lazy){
                update(ls(sit), seg[sit].lazy);
                update(rs(sit), seg[sit].lazy);
                seg[sit].lazy = 0;
            }
        }

        void pull(int sit){
            seg[sit].value = std::max(seg[ls(sit)].value, seg[rs(sit)].value);
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

        int query_first(int sit, int l, int r, int ql, int qr, T val){
            if (ql > r || qr < l){
                return -1;
            }
            if (seg[sit].value < val){
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

const int N = 100010;

ll a[N], b[N];

void solve(){
    int n, m, q;
    std::cin >> n >> m >> q;
    for (int i = 0; i < n; ++ i){
        std::cin >> a[i];
    }
    for (int i = 0; i < m; ++ i){
        std::cin >> b[i];
    }
    Seg::Seg seg(m);
    for (int i = 0; i < m; ++ i){
        seg.seg[i + seg.maximum].value = b[i];
        seg.seg[i + seg.maximum].coe[0] = 1;
        seg.seg[i + seg.maximum].coe[1] = i;
    }
    seg.init();
    Seg1::Seg seg1(m - 1);
    for (int i = 0; i < m - 1; ++ i){
        seg1.seg[i + seg1.maximum].value = b[i + 1] - b[i];
    }
    seg1.init();
    while (q --){
        int type, k, d;
        std::cin >> type >> k >> d;
        if (type == 1){
            k = n - k;
            for (int i = k; i < n; ++ i){
                a[i] += (i - (k - 1)) * d;
            }
        }
        else{
            k = m - k;
            seg.add(k, m - 1, d);
            seg1.add(std::max(0, k - 1), m - 2, d);
        }
        ll ans = 0;
        int cur = 0;
        for (int i = 0; i < n - 1; ++ i){
            ll delta = a[i + 1] - a[i];
            int pos = seg1.query_first(0, m - 2, delta);
            if (pos == -1){
                pos = m - 1;
            }
            ans += a[i] * (pos - cur + 1) + seg.query(cur, pos);
            cur = pos;
        }
        int pos = m - 1;
        ans += a[n - 1] * (pos - cur + 1) + seg.query(cur, pos);
        std::cout << ans << '\n';
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