#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> l(2, -1), r(2, -1);
        for(int i = 0; i < n; ++i) {
            int p = s[i] - '0';
            if(l[p] == -1) l[p] = i;
            r[p] = i;
        }
        if(l[0] == -1) cout << 0 << endl; // no 0
        else if(l[1] == -1) cout << 1 << endl; // no 1
        else {
            // 0 and 1
            int ok = 0;
            for(int i = l[0]; i <= r[0]; ++i) {
                if(s[i] == '1') {
                    ok = 1;
                    break;
                }
            }
            cout << 1 + ok << '\n';
        }
    }
}