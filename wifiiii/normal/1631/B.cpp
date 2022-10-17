#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        auto check = [&]() -> int {
            for(int i = n - 1; i >= 0; --i) {
                if(a[i] != a[n - 1]) return i;
            }
            return -1;
        };
        int p = -1, ans = 0;
        while((p = check()) != -1) {
            ans += 1;
            for(int i = p, j = 0; i >= 0 && j < n - 1 - p; --i, ++j) a[i] = a[n - 1];
        }
        cout << ans << '\n';
    }
}