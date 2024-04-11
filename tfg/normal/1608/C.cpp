#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n), b(n), pa(n), pb(n);
        std::vector<bool> vis(n, false);
        std::vector<int> q;
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
            pa[i] = i;
        }
        std::sort(pa.begin(), pa.end(), [&](int v1, int v2) { return a[v1] < a[v2]; });
        for(int i = 0; i < n; i++) {
            std::cin >> b[i];
            pb[i] = i;
        }
        std::sort(pb.begin(), pb.end(), [&](int v1, int v2) { return b[v1] < b[v2]; });
        int idx_a = n-1, idx_b = n-1;
        int st = pa[n-1];
        vis[st] = true;
        q.push_back(st);
        for(int rep = 0; rep < (int) q.size(); rep++) {
            int on = q[rep];
            while(idx_a >= 0 && a[pa[idx_a]] > a[on]) {
                int to = pa[idx_a];
                if(!vis[to]) {
                    q.push_back(to);
                    vis[to] = true;
                }
                idx_a--;
            }
            while(idx_b >= 0 && b[pb[idx_b]] > b[on]) {
                int to = pb[idx_b];
                if(!vis[to]) {
                    q.push_back(to);
                    vis[to] = true;
                }
                idx_b--;
            }
        }
        std::string ans(n, '0');
        for(auto x : q) ans[x] = '1';
        std::cout << ans << '\n';
    }
}