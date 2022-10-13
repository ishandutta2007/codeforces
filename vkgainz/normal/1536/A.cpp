#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        bool work = true;
        bool neg = false;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] < 0) neg = true;
        }
        work = (neg);
        if(!work) {
            cout << "YES" << "\n";
            cout << 101 << "\n";
            for(int i = 0; i <= 100; i++)
                cout << i << " ";
            cout << "\n";
        }
        else cout << "NO" << "\n";
    }
}