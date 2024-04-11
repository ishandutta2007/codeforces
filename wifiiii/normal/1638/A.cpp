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
        vector<int> suf(n, a.back());
        for(int i = n - 2; i >= 0; --i) suf[i] = min(suf[i + 1], a[i]);
        vector<int> ans = a;
        for(int i = 0; i < n; ++i) {
            if(a[i] != suf[i]) {
                for(int j = i + 1; j < n; ++j) {
                    vector<int> b = a;
                    reverse(b.begin() + i, b.begin() + j + 1);
                    ans = min(ans, b);
                }
                break;
            }
        }
        for(int i : ans) cout << i << ' '; cout << '\n';
    }
}