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
        ll sum = accumulate(a.begin(), a.end(), 0ll);
        int k = sum % n, r = n - k;
        cout << 1ll * k * r << '\n';
    }
}