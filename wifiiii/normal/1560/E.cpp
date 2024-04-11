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
        vector<int> cnt(26), vis(26);
        for(char c : s) cnt[c - 'a']++;
        int num = 0;
        for(int i = 0; i < 26; ++i) if(cnt[i]) ++num;
        string x, y;
        int len = 0, ok = 1;
        for(int i = s.size() - 1; i >= 0; --i) {
            if(vis[s[i] - 'a']) continue;
            if(cnt[s[i] - 'a'] % num) {
                ok = 0;
                break;
            }
            len += cnt[s[i] - 'a'] / num;
            --num;
            vis[s[i] - 'a'] = 1;
            y += s[i];
        }
        if(!ok) {
            cout << -1 << endl;
            continue;
        }
        reverse(y.begin(), y.end());
        x = s.substr(0, len);
        string qwq = x, xx = x;
        for(char c : y) {
            string nxt;
            copy_if(x.begin(), x.end(), back_inserter(nxt), [&](char d) {return d != c;});
            qwq += nxt;
            x = nxt;
        }
        if(qwq == s) cout << xx << " " << y << endl;
        else cout << -1 << endl;
    }
}