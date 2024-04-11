#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        string t = "";
        for(int i = 0; i < n; i++) t += s[i];
        sort(t.begin(), t.end());
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += t[i] != s[i];
        cout << ans << "\n";
    }
}