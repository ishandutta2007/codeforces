#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if(sum == n) {
            cout << 0 << "\n";
        }
        else if(sum < n) {
            cout << 1 << "\n";
        }
        else {
            cout << sum - n << "\n";
        }
    }
}