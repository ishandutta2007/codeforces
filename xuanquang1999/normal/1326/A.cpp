#include <bits/stdc++.h>

using namespace std;

int main() {    
    int nTest;
    cin >> nTest;
    while (nTest--) {
        int n;
        cin >> n;

        string ans;
        if (n == 1) {
            ans = "-1";
        } else {
            ans = "2";
            for(int i = 2; i <= n; ++i)
                ans += '3';
        }
        
        cout << ans << endl;
    }
    
    return 0;
}