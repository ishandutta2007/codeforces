//
// Created by  on 2022/1/16.
//

//
// Created by  on 2022/1/6.
//

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
// #define printf dont_use_printf
#define endl dont_use_endl

using ll = int64_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

//
// Created by  on 2022/1/16.
//

#include <bits/stdc++.h>

template <typename T>
class Stack{
private:
    std::vector <T> a;

    void calculate_min(){
        int n = a.size();
        std::vector <int> stack;
        for (int i = 0; i < n; ++ i){
            while (!stack.empty() && a[stack.back()] > a[i]){
                r[stack.back()] = i;
                stack.pop_back();
            }
            if (!stack.empty()){
                l[i] = stack.back();
            }
            stack.emplace_back(i);
        }
    }

    void calculate_max(){
        int n = a.size();
        std::vector <int> stack;
        for (int i = 0; i < n; ++ i){
            while (!stack.empty() && a[stack.back()] < a[i]){
                r[stack.back()] = i;
                stack.pop_back();
            }
            if (!stack.empty()){
                l[i] = stack.back();
            }
            stack.emplace_back(i);
        }
    }

public:
    std::vector <int> l, r;

    Stack(const std::vector <T> &el, int o):a(), l(), r(){
        int n = el.size();
        a = el;
        l.resize(n, -1);
        r.resize(n, n);
        for (int i = 0; i < n; ++ i){
            a[i] = el[i];
        }
        if (o == 0){
            calculate_min();
        }
        else if (o == 1){
            calculate_max();
        }
        else{
            assert(false);
        }
    }
};

#include <bits/stdc++.h>

namespace Seg{
    using T = pii;

    class Node{
    public:
        int value, value1;
        int lazy;

        Node():value(), value1(), lazy(){}
        Node(int value, int value1, int lazy):value(value), value1(value1), lazy(lazy){}
    };

    class Seg{
#define ls(u) ((u) << 1)
#define rs(u) (((u) << 1) | 1)
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
            for (int i = maximum; i < maximum + maximum; ++ i){
                seg[i] = {0, 1, 0};
            }
            for (int i = maximum - 1; i; -- i){
                pull(i);
                seg[i].lazy = 0;
            }
        }

        void update(int sit, int value){
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
            int a = seg[ls(sit)].value, b = seg[ls(sit)].value1;
            int c = seg[rs(sit)].value, d = seg[rs(sit)].value1;
            seg[sit].value = std::max(a, c);
            seg[sit].value1 = a > c ? b : a < c ? d : b + d;
        }

        void add(int sit, int l, int r, int ql, int qr, int value){
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

        void add(int l, int r, int value){
            add(1, 0, maximum - 1, l, r, value);
        }
    };
}

const int N = 1000010;

std::vector <int> vec[N];

namespace fastIO {
#define BSIZE (100000)
    bool IOerror = 0;
    inline char nc() {
        static char buf[BSIZE], *p1 = buf + BSIZE, *pend = p1;
        if (p1 == pend) {
            p1 = buf; pend = buf + fread(buf, 1, BSIZE,stdin);
            if (pend == p1) {IOerror = 1; return -1;}
        }
        return *p1++;
    }
    template <typename T>
    inline void read(T &x) {
        char ch; int f = 1;
        while(isspace(ch = nc())||ch=='-') if(ch=='-') f=-1;
        if (IOerror) return;
        for (x=ch-'0'; isdigit(ch = nc()); x=x*10+ch-'0');
        x *= f;
    }
#undef BSIZE
}

using fastIO::read;

void solve(){
    int n;
    read(n);
    std::vector <ll> a(n);
    for (int i = 0; i < n; ++ i){
        read(a[i]);
    }
    Stack<ll> s1(a, 0);
    Stack<ll> s2(a, 1);
    for (int i = 0; i < n; ++ i){
        int id = __builtin_popcountll(a[i]);
        vec[id].emplace_back(i);
    }
    ll ans = 0;
    Seg::Seg seg(n);
    for (int i = 0; i < 70; ++ i){
        if (vec[i].empty()){
            continue;
        }
        seg.init();
        using piiii = std::tuple <int, int, int, int>;
        std::vector <piiii> event;
        for (auto id: vec[i]){
            int l = s1.l[id], r = s1.r[id];
            event.emplace_back(l + 1, id, r - 1, 1);
            event.emplace_back(id + 1, id, r - 1, -1);
            l = s2.l[id], r = s2.r[id];
            event.emplace_back(l + 1, id, r - 1, 1);
            event.emplace_back(id + 1, id, r - 1, -1);
        }
        std::sort(event.begin(), event.end());
        pii lastp = {0, 0};
        int cur = 0;
        for (int j = 0; j < n; ++ j){
            bool added = false;
            while (cur < int(event.size()) && std::get <0>(event[cur]) <= j){
                auto [_, l, r, val] = event[cur];
                seg.add(l, r, val);
                added = true;
                ++ cur;
            }
            pii p;
            if (added){
                p = {seg.seg[1].value, seg.seg[1].value1};
                lastp = p;
            }
            else{
                p = lastp;
            }
            if (p.first == 2){
                ans += p.second;
            }
        }
    }
    printf("%lld\n", ans);
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