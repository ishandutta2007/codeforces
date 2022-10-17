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
        for(int i = 0, j = 0; i < s.size(); i = j) {
            while(j < s.size() && s[i] == s[j]) ++j;
            if(j - i == 1) ok = 0;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}