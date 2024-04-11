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
        auto check = [&](int s) {
            for(int i = 0; i < n; ++i) {
                if(abs(a[i] - (s + i)) > 1) return 0;
            }
            return 1;
        };
        if(check(a[0] - 1) || check(a[0]) || check(a[0] + 1)) cout << "YES\n";
        else cout << "NO\n";
    }
}