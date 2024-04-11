#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct SegTree {
    void init(int _n) {
        n = _n;
        tree.assign(2*n, 0);
    }

    void upd(int l, int r, int x) {
        for(l += n, r += n; l < r; l /= 2, r /= 2) {
            if(l & 1) tree[l++] += x;
            if(r & 1) tree[--r] += x;
        }
    }

    int qry(int pos) {
        int ans = 0;
        for(pos += n; pos > 0; pos /= 2) {
            ans += tree[pos];
        }
        return ans;
    }

    int n;
    std::vector<int> tree;
};

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        SegTree tree;
        tree.init(n);
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
            tree.upd(i, i+1, a[i]);
        }
        std::vector<int> ans(n, -1);
        int f[2] = {0, 0};
        for(int i = 0; i < n; i++) {
            // if this position is 0, then position f[0] should be 0
            int val = tree.qry(f[0]) == 0 ? 0 : 1;
            f[val]++;
            if(val) {
                tree.upd(i, i+1, -i);
            }
            tree.upd(i+1-f[1], i+1, -1);
            std::cout << val << (i + 1 == n ? '\n' : ' ');
        }
    }
}