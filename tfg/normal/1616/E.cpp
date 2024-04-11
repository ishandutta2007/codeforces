#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
    int q;
    std::cin >> q;
    while(q--) {
        int n;
        std::string s, t;
        std::cin >> n >> s >> t;
        long long ans = 1e18;
        std::vector<int> pt(26, 0), id(26, 1e9);
        std::vector<std::vector<int>> pos(26);
        FenwickTree<int> tree;
        tree.init(n+1);
        for(int i = 0; i < n; i++) {
            if(pos[s[i]-'a'].empty()) {
                id[s[i]-'a'] = i;
            }
            pos[s[i]-'a'].push_back(i);
            tree.upd(i+1, 1);
        }
        long long cost = 0;
        for(int i = 0; i < n; i++) {
            // i-th position breaks tie
            for(int j = 0; j < t[i] - 'a'; j++) if(pt[j] < (int) pos[j].size()) {
                ans = std::min(ans, cost + id[j]);
            }
            // now making i-th position being equal
            int j = t[i] - 'a';
            if(pt[j] == (int) pos[j].size()) break;
            // fixing others
            for(int x = 0; x < 26; x++) if(id[x] > id[j]) {
                id[x]--;
            }
            cost += id[j];
            assert(pt[j] < (int) pos[j].size());
            tree.upd(pos[j][pt[j]] + 1, -1);
            assert(id[j] == tree.qry(pos[j][pt[j]]));
            pt[j]++;
            if(pt[j] < (int) pos[j].size()) {
                id[j] = tree.qry(pos[j][pt[j]]);
            }
        }
        if(ans >= (long long) 1e17) {
            ans = -1;
        }
        std::cout << ans << '\n';
    }
}