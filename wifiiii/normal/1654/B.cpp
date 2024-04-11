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
        vector<int> cnt(26);
        for(char c : s) cnt[c - 'a']++;
        for(int i = 0; i < s.size(); ++i) {
            if(cnt[s[i] - 'a'] == 1) {
                cout << s.substr(i) << '\n';
                break;
            } else {
                cnt[s[i] - 'a']--;
            }
        }
    }
}