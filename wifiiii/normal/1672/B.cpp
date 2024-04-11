#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int ok = 1;
        if(s.back() != 'B') ok = 0;
        int cnt = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'B') {
                if(cnt == 0) ok = 0;
                --cnt;
            } else {
                ++cnt;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}