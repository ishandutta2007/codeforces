#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>

std::mt19937 rng((unsigned int) std::chrono::steady_clock::now().time_since_epoch().count());

typedef unsigned long long ull;

const int ms = 30;

struct Hash {
    unsigned long long a[ms+1];

    void init() {
        auto dist = std::uniform_int_distribution<unsigned int>();
        for(int i = 0; i <= ms; i++) {
            a[i] = dist(rng);
        }
    }
    void erase() {
        memset(a, 0, sizeof a);
    }
    Hash operator + (const Hash &o) const {
        Hash ans;
        for(int i = 0; i < ms; i++) {
            ans.a[i] = a[i] + o.a[i];
        }
        ans.a[ms] = a[ms] ^ o.a[ms];
        return ans;
    }
    Hash operator - (const Hash &o) const {
        Hash ans;
        for(int i = 0; i < ms; i++) {
            ans.a[i] = a[i] - o.a[i];
        }
        ans.a[ms] = a[ms] ^ o.a[ms];
        return ans;
    }
    void operator += (const Hash &o) {
        for(int i = 0; i < ms; i++) {
            a[i] += o.a[i];
        }
        a[ms] ^= o.a[ms];
    }
    void operator -= (const Hash &o) {
        for(int i = 0; i < ms; i++) {
            a[i] -= o.a[i];
        }
        a[ms] ^= o.a[ms];
    }
};
std::map<int, Hash> h;
Hash getHashValue(int v) {
    //h[v] = v;
    if(h.find(v) == h.end()) {
        Hash val;
        val.init();
        h[v] = val;
        //std::cout << "mapped " << v << " to " << h[v] << '\n';
    }
    return h[v];
}
template <class T>
class FenwickTree {
public:
    void init(int _n) {
        this->n = _n;
        T zero;
        zero.erase();
        bit.assign(n + 1, zero);
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
        T ans;
        ans.erase();
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
    std::vector<int> a(n);
    FenwickTree<Hash> fw;
    fw.init(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        fw.upd(i+1, getHashValue(a[i]));
    }
    for(int i = 0; i < q; i++) {
        int t;
        std::cin >> t;
        if(t == 1) {
            int x, v;
            std::cin >> x >> v;
            x--;
            fw.upd(x+1, getHashValue(v) - getHashValue(a[x]));
            a[x] = v;
        } else {
            int l, r, v;
            std::cin >> l >> r >> v;
            l--;
            auto val = fw.qry(r) - fw.qry(l);
            bool ans = (r - l) % v == 0;
            for(int j = 0; j < ms; j++) {
                ans = ans && val.a[j] % v == 0;
            }
            if(v % 2 == 0) {
                ans = ans && val.a[ms] == 0;
            }
            std::cout << (ans ? "YES\n" : "NO\n");
        }
    }
}