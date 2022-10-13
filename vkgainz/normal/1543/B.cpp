#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        long long sum = 0LL;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        int l = sum % n, r = n - l;
        cout << l * 1LL * r << "\n";
    }
}