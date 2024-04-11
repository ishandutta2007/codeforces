#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), pre(n+1);
        for(int i = 0; i < n; ++i) cin >> a[i], pre[i+1] = pre[i] ^ a[i];
        if(pre.back() == 0) {
            cout << "YES" << endl;
            continue;
        }
        int ok = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int l = pre[i+1], m = pre[j+1] ^ pre[i+1], r = l ^ m ^ pre.back();
                if(l == m && m == r) {
                    ok = 1;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}