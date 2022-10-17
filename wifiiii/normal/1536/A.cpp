#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int ok = 1;
        unordered_map<int, int> vis;
        for(int i = 0; i < n; ++i) {
            if(a[i] < 0) ok = 0;
            if(vis[a[i]]) ok = 0;
            vis[a[i]] = 1;
        }
        if(!ok) {
            cout << "no\n";
        } else {
            cout << "yes\n";
            int mx = *max_element(a.begin(), a.end());
            cout << mx + 1 << endl;
            for(int i = 0; i <= mx; ++i) cout << i << " ";
            cout << endl;
        };
    }
}