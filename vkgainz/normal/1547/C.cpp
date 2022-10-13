#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int k, n, m; cin >> k >> n >> m;
        vector<int> a(n), b(m);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
        vector<int> ans(n + m);
        bool work = true;
        for(int x = 0; x < n + m; x++) {
            if(a.empty()) {
                if(b.back() > k) {
                    work = false;
                    break;
                }
                ans[x] = b.back();
                if(b.back() == 0) ++k;
                b.pop_back();
            }
            else if(b.empty()) {
                if(a.back() > k) {
                    work = false;
                    break;
                }
                ans[x] = a.back();
                if(a.back() == 0) ++k;
                a.pop_back();
            }
            else {
                if(min(a.back(), b.back()) > k) {
                    work = false;
                    break;
                }
                if(a.back() < b.back()) {
                    ans[x] = a.back();
                    if(a.back() == 0) ++k;
                    a.pop_back();
                }
                else {
                    ans[x] = b.back();
                    if(b.back() == 0) ++k;
                    b.pop_back();

                }
            }
        }
        if(!work) {
            cout << -1 << "\n";
            continue;
        }
        for(int i = 0; i < n + m; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}