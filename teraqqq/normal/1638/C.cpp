#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> st;
    
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        
        if (st.empty() || st.back() < x) {
            st.push_back(x);
        } else {
            int k = st.back();
            while (!st.empty() && st.back() > x) st.pop_back();
            st.push_back(k);
        }
    }
    
    cout << size(st) << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}