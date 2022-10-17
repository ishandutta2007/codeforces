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
        auto check = [&](string s) {
            int i = 0, j = s.size() - 1;
            while(i < j) {
                if(s[i] != s[j]) return 1;
                ++i, --j;
            }
            return 0;
        };
        if(check(s + "a")) {
            cout << "YES" << endl;
            cout << s + "a" << endl;
        } else if(check("a" + s)) {
            cout << "YES" << endl;
            cout << "a" + s << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}