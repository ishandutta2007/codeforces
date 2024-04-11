#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(2 * n);
        int e = 0, o = 0;
        for(int i = 0; i < 2 * n; i++) {
            cin >> a[i];
            if(a[i] % 2) ++o;
            else ++e;
        }
        if(e == o) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}