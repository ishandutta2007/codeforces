#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<int> ans(n);
        int cur = 0;
        for(int i = 1; i < n; ++i) {
            cur |= a[i-1];
            ans[i] = cur & ~a[i];
        }
        for(int i : ans) cout << i << " ";
        cout << '\n';
    }
}