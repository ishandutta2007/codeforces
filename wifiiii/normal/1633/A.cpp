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
        if(stoi(s) % 7 == 0) {
            cout << s << '\n';
        } else {
            for(char c = '0'; c <= '9'; ++c) {
                s.back() = c;
                if(stoi(s) % 7 == 0) {
                    cout << s << '\n';
                    break;
                }
            }
        }
    }
}