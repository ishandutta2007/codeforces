#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        string ans = "";
        string ref = "abcdefghijklmnopqrstuvwxyz";
        bool found = false;
        for(int i = 0; i < 26 && !found; i++) {
            string test = ref.substr(i, 1);
            bool off = false;
            for(int j = 0; j < n; j++) {
                if(s.substr(j, 1) == test) off = true;
            }
            if(!off) ans = test, found = true;
        }
        for(int i = 0; i < 26 && !found; i++) {
            for(int j = 0; j < 26 && !found; j++) {
                string test = ref.substr(i, 1) + ref.substr(j, 1);
                bool off = false;
                for(int k = 0; k < n - 1; k++) {
                    if(s.substr(k, 2) == test) off = true;
                }
                if(!off) ans = test, found = true;
            }
        }
        for(int i = 0; i < 26 && !found; i++) {
            for(int j = 0; j < 26 && !found; j++) {
                for(int k = 0; k < 26 && !found; k++) {
                    string test = ref.substr(i, 1) + ref.substr(j, 1) + ref.substr(k, 1);
                    bool off = false;
                    for(int l = 0; l < n - 2; l++) {
                        if(s.substr(l, 3) == test) off = true;
                    }
                    if(!off) ans = test, found = true;
                }
            }
        }
        cout << ans << "\n";
    }
}