#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> vis(n+1);
        map<string, int> mp;
        for(int i = 1;; ++i) {
            string s2;
            int x = i;
            while(x) {
                s2 += (x - 1) % 26 + 'a';
                x = (x - 1) / 26;
            }
            reverse(s2.begin(), s2.end());
            if(!vis[s2.size()]) {
                mp.clear();
                vis[s2.size()] = 1;
                for(int j = s2.size(); j <= n; ++j) {
                    mp[s.substr(j-s2.size(),s2.size())]=1;
                }
            }
            if(!mp[s2]) {
                cout << s2 << endl;
                break;
            }
        }
    }
}