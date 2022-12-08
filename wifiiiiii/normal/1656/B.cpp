#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> mp;
        for(int i = 0; i < n; ++i) cin >> a[i], mp[a[i]] = 1;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(mp[a[i] + k]) ans = 1;
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
}