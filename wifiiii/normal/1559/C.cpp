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
        if(a[0]) {
            cout << n + 1 << " ";
            for(int i = 1; i <= n; ++i) cout << i << " ";
            cout << endl;
        } else if(a.back() == 0) {
            for(int i = 1; i <= n + 1; ++i) cout << i << " ";
            cout << endl;
        } else {
            for(int i = 0; i < n; ++i) {
                if(a[i]) {
                    assert(i > 0 && a[i-1] == 0);
                    for(int j = 1; j <= i; ++j) cout << j << " ";
                    cout << n + 1 << " ";
                    for(int j = i + 1; j <= n; ++j) cout << j << " ";
                    cout << endl;
                    break;
                }
            }
        }
    }
}