#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<int> compose(std::vector<int> a, const std::vector<int> &b) {
    for(auto &x : a) x = b[x];
    return a;
}

std::vector<int> fexp(std::vector<int> p, int e) {
    int n = (int) p.size();
    std::vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        ans[i] = i;
    }
    for(; e > 0; e /= 2) {
        if(e & 1) ans = compose(ans, p);
        p = compose(p, p);
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    std::vector<std::vector<int>> pos(n);
    for(int i = 0; i < n; i++) {
        std::cin >> p[i];
        p[i]--;
        pos[p[i]].push_back(i);
    }
    int dead = 0;
    for(int i = 0; i < n; i++) if(!pos[i].empty()) {
        dead += (int) pos[i].size() - 1;
        pos[i].clear();
    }
    std::vector<int> a(n);
    int mx = 0;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        mx = std::max(mx, a[i]);
    }
    int round = (mx - (n-1)) / dead;
    p = fexp(p, round);
    for(int i = 0; i < n; i++) {
        pos[p[i]].push_back(i);
    }
    std::set<int> missing;
    for(int i = 0; i < n; i++) {
        missing.insert(i);
    }
    std::vector<int> pt(n, 0);
    std::vector<int> ans(n, -1);
    for(int i = 0; i < n; i++) if(!pos[i].empty()) {
        // position i should be < n
        assert(a[i] < n);
        pt[i] = a[i];
        ans[pos[i][0]] = a[i];
        missing.erase(a[i]);
    }
    for(int i = 0; i < n; i++) if(ans[i] == -1) {
        int j = p[i];
        auto it = missing.lower_bound(pt[j]);
        assert(it != missing.end());
        ans[i] = *it;
        missing.erase(it);
    }
    for(int i = 0; i < n; i++) {
        assert(ans[i] > -1);
        std::cout << ans[i] + 1 << (i + 1 == n ? '\n' : ' ');
    }
}