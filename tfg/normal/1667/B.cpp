#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1e9;

struct SegTree {
    void init(int _n) {
        n = _n;
        tree.assign(2*n, -INF);
    }

    int qry(int l, int r) {
        int ans = -INF;
        for(l += n, r += n; l < r; l /= 2, r /= 2) {
            if(l & 1) ans = std::max(ans, tree[l++]);
            if(r & 1) ans = std::max(ans, tree[--r]);
        }
        return ans;
    }

    void upd(int x, int val) {
        x += n;
        tree[x] = std::max(tree[x], val);
        for(x /= 2; x > 0; x /= 2) {
            tree[x] = std::max(tree[x+x], tree[x+x+1]);
        }
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
        std::vector<long long> a(n), sum(n+1, 0);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
            sum[i+1] = sum[i] + a[i];
        }
        auto uni = sum;
        std::sort(uni.begin(), uni.end());
        SegTree tree1, tree2;
        std::vector<int> best(n+1, -INF);
        tree1.init(n+1), tree2.init(n+1);
        auto getID = [&](long long v) { return std::lower_bound(uni.begin(), uni.end(), v) - uni.begin(); };
        auto upd = [&](int id, int i, int ans) {
            best[id] = std::max(best[id], ans);
            tree1.upd(id, ans-i);
            tree2.upd(id, ans+i);
        };
        std::vector<int> dp(n, -INF);
        upd(getID(0), -1, 0);
        for(int i = 0; i < n; i++) {
            int id = getID(sum[i+1]);
            int ans = std::max(best[id], std::max(tree1.qry(0, id)+i, tree2.qry(id+1, n+1)-i));
            dp[i] = ans;
            upd(id, i, ans);
        }
        std::cout << dp.back() << '\n';
    }
}