#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string ans = "";
        if(n == 1) {
            cout << 'a' << "\n";
            continue;
        }
        else if(n % 2) {
            int x = (n - 2 - 1) / 2;
            for(int i = 0; i < x; i++)
                ans += 'a';
            ans += 'b';
            ans += 'c';
            for(int i = 0; i < x + 1; i++)
                ans += 'a';
        }
        else {
            int x = (n - 1 - 1) / 2;
            for(int i = 0; i < x; i++)
                ans += 'a';
            ans += 'b';
            for(int i = 0; i < x + 1; i++)
                ans += 'a';
        }
        cout << ans << "\n";
    }
}