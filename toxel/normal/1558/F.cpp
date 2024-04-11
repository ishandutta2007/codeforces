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

//
// Created by  on 2022/1/31.
//

#ifndef WORKSPACE_SEGMENTRANGE_H
#define WORKSPACE_SEGMENTRANGE_H

#include <bits/stdc++.h>

namespace Seg{
    using T = int;

    class Node{
    public:
        T value;
        T lazy;

        Node():value(), lazy(){}
        Node(T value, T lazy):value(value), lazy(lazy){}
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
            for (int i = maximum; i < maximum + maximum; ++ i){
                seg[i] = Node();
            }
            for (int i = maximum - 1; i; -- i){
                pull(i);
            }
        }

        void update(int sit, T value){
            seg[sit].value += value;
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

        T query(int sit, int l, int r, int ql, int qr){
            if (ql > r || qr < l){
                return INT_MIN;
            }
            if (ql <= l && qr >= r){
                return seg[sit].value;
            }
            push(sit);
            int mid = (l + r) / 2;
            return std::max(query(ls(sit), l, mid, ql, qr),
                    query(rs(sit), mid + 1, r, ql, qr));
        }

        T query(int l, int r){
            return query(1, 0, maximum - 1, l, r);
        }
    };
}

#endif //WORKSPACE_SEGMENTRANGE_H

//
// Created by  on 2022/1/6.
//

#ifndef WORKSPACE_BIT_H
#define WORKSPACE_BIT_H

#include <bits/stdc++.h>

template <typename T>
class BIT{
public:
    int sz;
    std::vector <T> vec;
    T sum;

    BIT(int size):sz(size + 1), vec(sz + 1), sum(0){}

    void add(int sit, T value){
        sum += value;
        for (sit += 1; sit < sz; sit += sit & -sit){
            vec[sit] += value;
        }
    }

    T query(int sit){
        T ret = 0;
        for (sit += 1; sit; sit -= sit & -sit){
            ret += vec[sit];
        }
        return ret;
    }

    T query_up(int sit){
        return sum - query(sit - 1);
    }

    T query(int l, int r){
        return query(r) - query(l - 1);
    }
};

#endif //WORKSPACE_BIT_H

void solve(){
    const int INF = -1e9;
    int n;
    std::cin >> n;
    std::vector <int> a(n + 1), inv(n + 1);
    for (int i = 1; i <= n; ++ i){
        std::cin >> a[i];
        inv[a[i]] = i;
    }
    Seg::Seg seg(n + 1);
    BIT <int> bit(n + 1), bit1(n + 1);
    for (int i = 1; i <= n; ++ i){
        seg.add(i, i, INF);
    }
    std::vector <int> vis(n + 1);
    int cur = 1;
    for (int i = 1; i <= n; ++ i){
        bit.add(i, 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        int pos = inv[i];
        int val = seg.query(pos, pos);
        seg.add(pos, pos, -val);
        bit.add(pos, -1);
        val = bit.query(pos);
        if (pos % 2 == 1){
            ++ val;
        }
        val += bit1.query_up(pos);
        bit1.add(pos, 1);
        seg.add(pos, pos, val);
        vis[pos] = true;
        while (cur <= n && vis[cur]){
            if (cur % 2 == 1){
                seg.add(cur, cur, -seg.query(cur, cur));
            }
            ++ cur;
        }
        seg.add(cur, pos - 1, 1);
        seg.add(pos + 1, n, -1);
        ans = std::max(ans, seg.query(1, n));
    }
    std::cout << ans << '\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
    std::cin >> test;
    while (test --){
        solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H