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
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i], b[i] -= a[i];
        if(accumulate(b.begin(), b.end(), 0)) {
            cout << -1 << endl;
            continue;
        }
        vector<pair<int,int>> ans;
        while(any_of(b.begin(), b.end(), [](int x) {return x != 0;})) {
            int pos = find_if(b.begin(), b.end(), [](int x) {return x > 0;}) - b.begin();
            int neg = find_if(b.begin(), b.end(), [](int x) {return x < 0;}) - b.begin();
            ans.push_back({neg, pos});
            b[pos]--;
            b[neg]++;
        }
        cout << ans.size() << endl;
        for(auto [u, v] : ans) {
            cout << u + 1 << " " << v + 1 << '\n';
        }
    }
}