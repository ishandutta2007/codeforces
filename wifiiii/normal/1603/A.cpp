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
        ll g = 1;
        int ok = 1;
        for(int i = 0; i < n; ++i) {
            if(g <= 1e10) g = lcm(g, i + 2);
            if(a[i] % g == 0) {
                ok = 0;
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
}