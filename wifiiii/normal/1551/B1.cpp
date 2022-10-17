#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        vector<int> cnt(26);
        for(char c : s) cnt[c - 'a']++;
        int c1 = 0, ans = 0;
        for(int i = 0; i < 26; ++i) {
            if(cnt[i] == 1) ++c1;
            else if(cnt[i] >= 2) ++ans;
        }
        ans += c1 / 2;
        cout << ans << '\n';
    }
}