#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int ans = -1;
        for(int i = 0; i < 10; i++) {
            //favor first
            int lf = 5 - (i / 2 + 1), ls = 5 - ((i + 1) / 2);
            int fi = 0, se = 0;
            for(int j = 0; j <= i; j++) {
                if(j % 2 == 0) {
                    if(s[j] == '1' || s[j] == '?') ++fi;
                }
                else {
                    if(s[j] == '1') ++se;
                }
            }
            if(se + ls < fi || fi + lf < se) ans = i;
            //favor sec
            fi = 0, se = 0;
            for(int j = 0; j <= i; j++) {
                if(j % 2 == 0) {
                    if(s[j] == '1') ++fi;
                }
                else {
                    if(s[j] == '1' || s[j] == '?') ++se;
                }
            }
            if(se + ls < fi || fi + lf < se) ans = i;
            if(ans != -1) break;
        }
        if(ans + 1 == 0) cout << 10 << "\n";
        else cout << ans + 1 << "\n";
    }
}