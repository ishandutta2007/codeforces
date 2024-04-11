#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size(), ok = 0;
        auto rev = [](string s) {
            reverse(s.begin(), s.end());
            return s;
        };
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                for(int k = j; k >= 0; --k) {
                    // [i, j] + (j, k, -1]
                    int sz = j - i + 1 + j - k;
                    if(sz != m) continue;
                    if(s.substr(i, j - i + 1) + rev(s.substr(k, j - k)) == t) {
                        ok = 1;
                    }
                }
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}