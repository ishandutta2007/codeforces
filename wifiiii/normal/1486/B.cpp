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
        vector<int> x(n), y(n);
        for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];
        if(n & 1) cout << 1 << endl;
        else {
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());
            int m = n / 2 - 1;
            cout << 1ll * (x[m+1] - x[m] + 1) * (y[m+1] - y[m] + 1) << endl;
        }
    }
}