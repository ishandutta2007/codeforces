#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<int> b = a;
        sort(b.begin(), b.end());
        int ok = 1;
        for(int i = 0; i < n; ++i) {
            if(i < m && n - 1 - i < m && a[i] != b[i]) {
                ok = 0;
            }
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
}