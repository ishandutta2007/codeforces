#include<bits/stdc++.h>
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
        int f = 0;
        for(int i = 0; i + 1 < s.size(); ++i) {
            if(s[i] - '0' + s[i + 1] - '0' >= 10) {
                f = 1;
                break;
            }
        }
        if(f) {
            for(int i = s.size() - 2; i >= 0; --i) {
                if(s[i] - '0' + s[i + 1] - '0' >= 10) {
                    int x = s[i] - '0' + s[i + 1] - '0';
                    s[i] = '0' + x / 10;
                    s[i + 1] = '0' + x % 10;
                    break;
                }
            }
            cout << s << '\n';
        } else {
            int x = s[0] - '0' + s[1] - '0';
            cout << x;
            cout << s.substr(2);
            cout << '\n';
        }
    }
}