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
        int k = 0;
        vector<int> vis(26);
        for(char c : s) {
            k += !vis[c - 'a']++;
        }
        int ok = 1;
        for(int i = 0; i + k < s.size(); ++i) {
            if(s[i] != s[i + k]) {
                ok = 0;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}