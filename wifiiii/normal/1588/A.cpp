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
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ok = 1;
        for(int i = 0; i < n; ++i) {
            if(a[i] != b[i] && a[i] + 1 != b[i]) {
                ok = 0;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}