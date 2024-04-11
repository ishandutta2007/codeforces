#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> a(n), b(m);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < m; ++i) cin >> b[i];
        int i = 0, j = 0;
        vector<int> ans;
        int ok = 1;
        while(i < n || j < m) {
            if(i < n && a[i] <= k) {
                if(!a[i]) ++k;
                ans.push_back(a[i]);
                ++i;
            } else if(j < m && b[j] <= k) {
                if(!b[j]) ++k;
                ans.push_back(b[j]);
                ++j;
            } else {
                ok = 0;
                break;
            }
        }
        if(ok) {
            for(int i : ans) {
                cout << i << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}