#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        char c;
        cin >> s >> c;
        int ok = 0;
        for(int i = 0; i < s.size(); i += 2) {
            if(s[i] == c) ok = 1;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}