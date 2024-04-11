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
        int ok = 1;
        for(int i = 0; i < n; ++i) {
            cin >> a[i], --a[i];
            if(a[i] % 2 != i % 2) ok = 0;
        }
        if(!ok) {
            cout << -1 << endl;
            continue;
        }
        vector<int> ans;
        auto go = [&](int x) {
            ++x;
            if(x == 1) return;
            assert(x <= n && x % 2);
            ans.push_back(x);
            reverse(a.begin(), a.begin() + x);
        };
        for(int i = n - 1; i >= 1; i -= 2) {
            int p1 = find(a.begin(), a.end(), i - 1) - a.begin();
            int p2 = find(a.begin(), a.end(), i) - a.begin();
            assert(p2 % 2 == 0);
            assert(p1 % 2);
            // ... p1 ... p2
            go(p2);
            p1 = find(a.begin(), a.end(), i - 1) - a.begin();
            p2 = find(a.begin(), a.end(), i) - a.begin();
            // p2 ... p1
            go(p1 - 1);
            p1 = find(a.begin(), a.end(), i - 1) - a.begin();
            p2 = find(a.begin(), a.end(), i) - a.begin();
            // ... p2 p1 ...
            go(p1 + 1);
            p1 = find(a.begin(), a.end(), i - 1) - a.begin();
            p2 = find(a.begin(), a.end(), i) - a.begin();
            // ... p1 p2 ...
            go(p2);
            // p2 p1 ...
            go(i);
            // ... p1 p2
        }
        cout << ans.size() << '\n';
        for(int i : ans) cout << i << " ";
        cout << endl;
    }
}