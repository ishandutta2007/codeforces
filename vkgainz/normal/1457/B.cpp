#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int a[n];
        for(int i=0;i<n;i++) {
            cin >> a[i];
            --a[i];
        }
        int ans = 1000000;
        for(int c=0;c<=100;c++) {
            int curr = 0;
            for(int i=0;i<n;i++) {
                if(a[i]==c) continue;
                ++curr;
                i+=k-1;
            }
            ans = min(ans, curr);
        }
        cout << ans << "\n";
    }
}