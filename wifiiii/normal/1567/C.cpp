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
        int x = 0, y = 0;
        for(int i = 0; i < s.size(); i += 2) {
            x = x * 10 + s[i] - '0';
        }
        for(int i = 1; i < s.size(); i += 2) {
            y = y * 10 + s[i] - '0';
        }
        cout << 1ll * (x + 1) * (y + 1) - 2 << endl;
    }
}