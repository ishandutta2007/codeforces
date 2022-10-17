#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        vector<int> pos(26, -1);
        int ok = 1, mx = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(pos[s[i] - 'a'] != -1) ok = 0;
            pos[s[i] - 'a'] = i;
            mx = max(mx, s[i] - 'a');
        }
        if(pos[0] == -1) ok = 0;
        int l = pos[0], r = pos[0];
        for(int i = 1; i <= mx; ++i) {
            if(pos[i] == -1) {
                ok = 0;
                break;
            } else if(pos[i] == l - 1) {
                l -= 1;
            } else if(pos[i] == r + 1) {
                r += 1;
            } else {
                ok = 0;
                break;
            }
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
}