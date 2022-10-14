#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    
    if(n > m) {
        cout << 0 << "\n";
    } else {
        ll res = 1;
        for(int i = 0; i < n; i++) {
            for(int j=i+1; j < n; j++) {
                res *= abs(a[i] - a[j]);
                res%=m;
            }
        }
        
        cout << res << "\n";
    }
}