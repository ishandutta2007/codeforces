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
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) {return a[i] > a[j];});
        vector<int> ans(n);
        vector<int> o;
        for(int i = -n; i <= n; ++i) if(i) o.push_back(i);
        sort(o.begin(), o.end(), [&](int i, int j) {return abs(i) < abs(j);});
        ll res = 0;
        for(int i = 0; i < n; ++i) {
            res += 1ll * abs(o[i]) * a[ord[i]];
            ans[ord[i]] = o[i];
        }
        cout << res * 2 << '\n';
        cout << 0 << " ";
        for(int i : ans) cout << i << " "; cout << '\n';
    }
}