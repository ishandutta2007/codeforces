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
#define ls(u) (seg[ch[0]])
#define rs(u) (seg[ch[1]])
// #define OPERATE +

    const int INIT = 100010;
    // modify here
    const int BIT = 20;
    const int MAX = 1 << BIT;
    // T is type of value
    using T = int;

    class Seg;
    int sz;
    Seg *seg = nullptr;
    Seg *newnode();

    class Seg{
    public:
        Seg *ch[2];
        // Add other values by yourself
        T value, lazy;
        unsigned value0, value1;

        // do some clear here
        Seg():ch(), value(), value0(), value1(), lazy(){}

        void update(T val){
            unsigned x = value0 & val;
            value0 &= ~val;
            unsigned y = value1 & val;
            value1 &= ~val;
            value0 |= y;
            value1 |= x;
            lazy ^= val;
        }

        void pull(){
            value = value0 = value1 = 0;
            for (int i = 0; i < 2; ++ i){
                if (ch[i] != nullptr){
                    value += ch[i] -> value;
                    value0 |= ch[i] -> value0;
                    value1 |= ch[i] -> value1;
                }
            }
        }

        void push(int cur){
            if (!lazy){
                return;
            }
            if (lazy >> cur & 1){
                std::swap(ch[0], ch[1]);
            }
            for (int i = 0; i < 2; ++ i){
                if (ch[i] != nullptr){
                    ch[i] -> update(lazy);
                }
            }
            lazy = 0;
        }
    };

    Seg *newnode(){
        if (sz == 0){
            seg = new Seg[INIT]();
            sz = INIT;
        }
        return seg + (-- sz);
    }

    void add(Seg *&s, int l, int r, int ql, int qr, T val){
        if (ql > r || qr < l){
            return;
        }
        if (s == nullptr){
            s = newnode();
        }
        if (ql <= l && r <= qr){
            s -> value = 1;
            s -> value0 = ~ql;
            s -> value1 = ql;
            return;
        }
        int mid = (l + r) / 2;
        add(s -> ch[0], l, mid, ql, qr, val);
        add(s -> ch[1], mid + 1, r, ql, qr, val);
        s -> pull();
    }

    T query(Seg *s, int l, int r, int ql, int qr, int cur){
        if (s == nullptr){
            return 0;
        }
        if (ql > r || qr < l){
            return 0;
        }
        if (ql <= l && r <= qr){
            return s -> value;
        }
        s -> push(cur);
        int mid = (l + r) / 2;
        T ans = 0;
        ans += query(s -> ch[0], l, mid, ql, qr, cur - 1);
        ans += query(s -> ch[1], mid + 1, r, ql, qr, cur - 1);
        return ans;
    }

    /*
     * @param s, the original tree
     * @return split s into two trees: < l & > r, l <= <= r, returned in s, t respectively
     */
    void split(Seg *&s, Seg *&t, int l, int r, int ql, int qr, int cur){
        if (s == nullptr){
            t = nullptr;
            return;
        }
        if (ql > r || qr < l){
            t = nullptr;
            return;
        }
        if (ql <= l && r <= qr){
            t = s;
            s = nullptr;
            return;
        }
        s -> push(cur);
        int mid = (l + r) / 2;
        t = newnode();
        split(s -> ch[0], t -> ch[0], l, mid, ql, qr, cur - 1);
        split(s -> ch[1], t -> ch[1], mid + 1, r, ql, qr, cur - 1);
        s -> pull();
        t -> pull();
    }

    Seg *merge(Seg *u, Seg *v, int cur){
        if (u == nullptr) return v;
        if (v == nullptr) return u;
        if (cur >= 0){
            u -> push(cur);
            v -> push(cur);
        }
        else{
            u -> value = std::max(u -> value, v -> value);
            u -> value0 |= v -> value0;
            u -> value1 |= v -> value1;
        }
        u -> ch[0] = merge(u -> ch[0], v -> ch[0], cur - 1);
        u -> ch[1] = merge(u -> ch[1], v -> ch[1], cur - 1);
        if (cur >= 0){
            u -> pull();
        }
        return u;
    }

    void make_xor(Seg *s, int val){
        if (s == nullptr) return;
        s -> update(val);
    }

    void make_or(Seg *s, int cur, T val){
        if (s == nullptr || cur == -1){
            return;
        }
        int state = ((1 << (cur + 1)) - 1) & val & s -> value0 & s -> value1;
        if (state == 0){
            make_xor(s, ((1 << (cur + 1)) - 1) & val & s -> value0);
            return;
        }
        s -> push(cur);
        if (val >> cur & 1){
            make_xor(s -> ch[0], 1 << cur);
            s -> ch[1] = merge(s -> ch[0], s -> ch[1], cur - 1);
            s -> ch[0] = nullptr;
        }
        make_or(s -> ch[0], cur - 1, val);
        make_or(s -> ch[1], cur - 1, val);
        s -> pull();
    }

    void add(Seg *&s, int ql, int qr, T val){
        return add(s, 0, MAX - 1, ql, qr, val);
    }

    T query(Seg *s, int ql, int qr){
        return query(s, 0, MAX - 1, ql, qr, BIT - 1);
    }

    void split(Seg *&s, Seg *&t, int l, int r){
        split(s, t, 0, MAX - 1, l, r, BIT - 1);
    }

    Seg *merge(Seg *u, Seg *v){
        return merge(u, v, BIT - 1);
    }

    void make_or(Seg *s, T val){
        make_or(s, BIT - 1, val);
    }
#undef ls
#undef rs
}

const int N = 200010;

int a[N];

void solve(){
    int n, q;
    std::cin >> n >> q;
    for (int i = 0; i < n; ++ i){
        std::cin >> a[i];
    }
    std::sort(a, a + n);
    n = std::unique(a, a + n) - a;
    Seg::Seg *root = nullptr;
    for (int i = 0; i < n; ++ i){
        Seg::add(root, a[i], a[i], 1);
    }
    while (q --){
        int type;
        std::cin >> type;
        if (type <= 3){
            int l, r, x;
            std::cin >> l >> r >> x;
            Seg::Seg *other;
            Seg::split(root, other, l, r);
            if (type == 1){
                const int OP = (1 << 20) - 1;
                Seg::make_xor(other, OP);
                Seg::make_or(other, OP ^ x);
                Seg::make_xor(other, OP);
            }
            else if (type == 2){
                Seg::make_or(other, x);
            }
            else if (type == 3){
                Seg::make_xor(other, x);
            }
            root = Seg::merge(root, other);
        }
        else{
            int l, r;
            std::cin >> l >> r;
            std::cout << Seg::query(root, l, r) << '\n';
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