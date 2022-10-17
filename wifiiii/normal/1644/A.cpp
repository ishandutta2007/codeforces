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
        vector<int> pos(256);
        for(int i = 0; i < s.size(); ++i) pos[s[i]] = i;
        int ok = 1;
        for(char c : {'b', 'r', 'g'}) {
            if(pos[c] > pos[c - 'a' + 'A']) {
                ok = 0;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}