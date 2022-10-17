#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        int d = -1, ok = 1;
        for(int i = 0; i < n; ++i) {
            if(a[i] < b[i]) ok = 0;
            if(b[i] != 0) d = a[i] - b[i];
        }
        if(d != -1) {
            for(int i = 0; i < n; ++i) {
                if(max(0, a[i] - d) != b[i]) ok = 0;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}