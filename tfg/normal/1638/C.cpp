#include <iostream>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::stack<int> st;
        for(int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            if(st.empty() || st.top() < x) {
                st.push(x);
            } else {
                int rep = st.top();
                while(!st.empty() && st.top() >= x) st.pop();
                st.push(rep);
            }
        }
        std::cout << st.size() << '\n';
    }
}