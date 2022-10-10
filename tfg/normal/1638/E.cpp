#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class Info = int, class T = int>
struct ColorUpdate {
public:
    struct Range {
        Range(T _l = 0) : l(_l) {}
        Range(T _l, T _r, Info _v) : l(_l), r(_r), v(_v) { }
        T l, r;
        Info v;

        bool operator < (const Range &b) const { return l < b.l; }
    };

    std::vector<Range> erase(T l, T r) {
        std::vector<Range> ans;
        if(l >= r) return ans;
        auto it = ranges.lower_bound(l);
        if(it != ranges.begin()) {
            it--;
            if(it->r > l) {
                auto cur = *it;
                ranges.erase(it);
                ranges.insert(Range(cur.l, l, cur.v));
                ranges.insert(Range(l, cur.r, cur.v));
            }
        }
        it = ranges.lower_bound(r);
        if(it != ranges.begin()) {
            it--;
            if(it->r > r) {
                auto cur = *it;
                ranges.erase(it);
                ranges.insert(Range(cur.l, r, cur.v));
                ranges.insert(Range(r, cur.r, cur.v));
            }
        }
        for(it = ranges.lower_bound(l); it != ranges.end() && it->l < r; it++) {
            ans.push_back(*it);
        }
        ranges.erase(ranges.lower_bound(l), ranges.lower_bound(r));
        return ans;
    }

    std::vector<Range> upd(T l, T r, Info v) {
        auto ans = erase(l, r);
        ranges.insert(Range(l, r, v));
        return ans;
    }

    bool exists(T x) {
        auto it = ranges.upper_bound(x);
        if(it == ranges.begin()) return false;
        it--;
        return it->l <= x && x < it->r;
    }

    Range element(T x) {
        auto it = ranges.upper_bound(x);
        it--;
        return *it;
    }
    std::set<Range> ranges;
};

template <class T>
class FenwickTree {
public:
    void init(int _n) {
        this->n = _n;
        bit.assign(n + 1, 0);
    }

    void init(const std::vector<T> &a) {
        n = a.size();
        bit.assign(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            bit[i] += a[i - 1];
            if(i + (i & -i) <= n) {
                bit[i + (i & -i)] += bit[i];
            }
        }
    }

    T qry(int x) {
        x = std::min(x, (int)bit.size() - 1);
        T ans = 0;
        for(; x > 0; x -= x & -x) {
            ans += bit[x];
        }
        return ans;
    }

    void upd(int x, T v) {
        if(x <= 0) return;
        for(; x <= n; x += x & -x) {
            bit[x] += v;
        }
    }
private:
    int n;
    std::vector<T> bit;
};

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, q;
    std::cin >> n >> q;
    std::map<int, long long> values;
    FenwickTree<long long> tree;
    tree.init(n+1);
    ColorUpdate<std::pair<int, long long>> color;
    color.upd(0, n, std::pair<int, long long>(1, 0));
    while(q--) {
        std::string op;
        std::cin >> op;
        if(op[0] == 'C') {
            int l, r, c;
            std::cin >> l >> r >> c;
            l--;
            for(auto range : color.upd(l, r, std::pair<int, long long>(c, values[c]))) {
                long long delta = values[range.v.first] - range.v.second;
                tree.upd(range.l+1, delta);
                tree.upd(range.r+1, -delta);
            }
        } else if(op[0] == 'A') {
            int c, x;
            std::cin >> c >> x;
            values[c] += x;
        } else {
            int x;
            std::cin >> x;
            x--;
            auto [col, val] = color.element(x).v;
            std::cout << values[col] - val + tree.qry(x+1) << '\n';
        }
    }
}