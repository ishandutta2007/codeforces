#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int x = min_element(a.begin(), a.end()) - a.begin();
        int y = max_element(a.begin(), a.end()) - a.begin();
        if(x > y) swap(x, y);
        int l = x, m = y - x - 1, r = n - 1 - y;
        cout << n - max(max(l, m), r) << '\n';
    }
}