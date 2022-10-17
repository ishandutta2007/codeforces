#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        vector<int> pos(26);
        for(int i = 0; i < s.size(); ++i) pos[s[i] - 'a'] = i;
        string x;
        cin >> x;
        int ans = 0;
        for(int i = 1; i < x.size(); ++i) {
            ans += abs(pos[x[i] - 'a'] - pos[x[i - 1] - 'a']);
        }
        cout << ans << '\n';
    }
}