#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &i : a)
            cin >> i;
        bool b = 0;
        int ans = 0;
        while(!is_sorted(a.begin(), a.end())) {
            for(int i = b; i + 1< n; i += 2) {
                if(a[i] > a[i + 1]) {
                    swap(a[i], a[i + 1]);
                } 
            }
            b = !b;
            ans++;
        }

        cout << ans << "\n";
    }
}