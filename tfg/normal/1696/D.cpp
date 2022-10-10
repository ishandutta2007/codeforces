#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <stack>

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
        std::vector<int> toLess(n+1, n+1), toUp(n+1, n+1);
        {
            std::stack<int> st;
            for(int i = 0; i < n; i++) {
                while(!st.empty() && a[i] < a[st.top()]) {
                    toLess[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        {
            std::stack<int> st;
            for(int i = 0; i < n; i++) {
                while(!st.empty() && a[i] > a[st.top()]) {
                    toUp[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        int ans = 0, on = 0;
        while(on != n-1) {
            int to = on;
            if(a[on] > a[on+1]) {
                int lim = toUp[on];
                while(toLess[to] < lim) to = toLess[to];
            } else {
                int lim = toLess[on];
                while(toUp[to] < lim) to = toUp[to];
            }
            on = to;
            ans++;
        }
        std::cout << ans << '\n';
    }
}