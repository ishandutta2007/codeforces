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
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int pos = 0, neg = 0;
        for(int x : a) {
            if(x > 0) ++pos;
            if(x < 0) ++neg;
        }
        if(pos >= 3 || neg >= 3) {
            cout << "NO\n";
            continue;
        }
        vector<int> b;
        int zero = 3;
        for(int x : a) {
            if(x == 0) {
                if(zero) --zero, b.push_back(0);
            } else {
                b.push_back(x);
            }
        }
        int m = b.size(), ok = 1;
        for(int i = 0; i < m; ++i) {
            for(int j = i + 1; j < m; ++j) {
                for(int k = j + 1; k < m; ++k) {
                    int x = b[i] + b[j] + b[k];
                    int fd = 0;
                    for(int y : b) if(y == x) fd = 1;
                    if(fd == 0) ok = 0;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}