#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = int64_t;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(auto &i : a) cin >> i;

    vector<int> b(n); for(auto &i : b) cin >> i;
    
    if(is_sorted(a.begin(), a.end())) {
        cout << "Yes" << '\n';
    } else if(count(b.begin(), b.end(), true) && count(b.begin(), b.end(), false)) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n'; 
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
        solve();
}