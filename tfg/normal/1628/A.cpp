#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::vector<int> suf(n+1, 0);
        {
            std::set<int> st;
            for(int i = n-1; i >= 0; i--) {
                st.insert(a[i]);
                suf[i] = suf[i+1];
                while(st.count(suf[i])) suf[i]++;
            }
        }
        int on = 0;
        std::vector<int> ans;
        while(on < n) {
            std::set<int> st;
            int want = suf[on];
            int got = 0;
            while(st.empty() || got < want) {
                assert(on < n);
                st.insert(a[on++]);
                while(st.count(got)) got++;
            }
            ans.push_back(got);
        }
        std::cout << ans.size() << '\n';
        for(int i = 0; i < (int) ans.size(); i++) {
            std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
        }
    }
}