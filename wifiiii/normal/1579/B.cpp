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
        sort(ord.begin(), ord.end(), [&](int i, int j) {return a[i] < a[j];});
        vector<int> r(n);
        for(int i = 0; i < n; ++i) r[ord[i]] = i;
        a = r;
        vector<array<int,3>> ans;
        for(int i = 0; i < n; ++i) {
            int p = find(a.begin(), a.end(), i) - a.begin();
            if(p == i) continue;
            ans.push_back({i, p, p - i});
            rotate(a.begin() + i, a.begin() + p, a.begin() + p + 1);
        }
        cout << ans.size() << endl;
        for(auto [u, v, w] : ans) {
            cout << u + 1 << " " << v + 1 << " " << w << endl;
        }
    }
}