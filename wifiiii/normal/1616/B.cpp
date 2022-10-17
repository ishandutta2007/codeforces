#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for(int i = 1; i < n; ++i) {
            if(s[i] > s[i - 1] || (s[i] == s[i - 1] && s[i] == s[0])) {
                s = s.substr(0, i);
                break;
            }
        }
        cout << s;
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }
}