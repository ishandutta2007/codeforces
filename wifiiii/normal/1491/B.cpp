#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, u, v;
        cin >> n >> u >> v;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int mx = 0;
        for(int i = 1; i < n; ++i) mx = max(mx, abs(a[i] - a[i-1]));
        if(mx == 0) cout << v + min(u, v) << endl;
        else if(mx == 1) cout << min(u, v) << endl;
        else cout << 0 << endl;
    }
}