#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        auto [l, r] = minmax_element(a.begin(), a.end());
        cout << l - a.begin() + 1 << " " << r - a.begin() + 1 << '\n';
    }
}