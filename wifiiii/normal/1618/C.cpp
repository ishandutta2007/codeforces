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
        vector<ll> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<ll> g(2);
        for(int i = 0; i < 2; ++i) {
            for(int j = i; j < n; j += 2) {
                g[i] = gcd(g[i], a[j]);
            }
        }
        vector<int> ok(2, 1);
        for(int i = 0; i < 2; ++i) {
            for(int j = i; j < n; j += 2) {
                if(a[j] % g[i ^ 1] == 0) {
                    ok[i ^ 1] = 0;
                }
            }
        }
        if(ok[0]) cout << g[0] << '\n';
        else if(ok[1]) cout << g[1] << '\n';
        else cout << 0 << '\n';
    }
}