#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        bool work = true;
        for(int i = 0; i < (int) s.length(); i++) {
            int mn = 27, mx = 0;
            for(int j = 0; j < (int) s.length(); j++) {
                if(s[j] - 'a' <= i)
                    mn = min(mn, j), mx = max(mx, j);
            }
            if(mx - mn != i) {
                work = false;
            }
        }
        if(work) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}