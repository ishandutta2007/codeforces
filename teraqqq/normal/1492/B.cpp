#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using vi = vector<int>;

void solve() {
    int n; cin >> n;
    vi a(n), st, b; for(int& x : a) cin >> x;
    for (int i = 0; i < n; ++i) {
        if (st.empty() || a[i] > a[st.back()])
            st.push_back(i);
    }
    
    int last = n;
    reverse(st.begin(), st.end());
    for (int i : st) {
        for (int j = i; j < last; ++j)
            b.push_back(a[j]);
        last = i;
    }

    for (int x : b) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}