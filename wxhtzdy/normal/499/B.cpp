#include <bits/stdc++.h>

using namespace std;

int main() {
        int n, m, i;
        string s, t;
        map<string, string> mp;
        
        cin >> n >> m;
        for (i = 0; i < m; i++) {
                cin >> s >> t;
                mp[s] = t;
        }
        for (i = 0; i < n; i++) {
                cin >> s;
                if (s.size() <= mp[s].size()) cout << s << " ";
                else cout << mp[s] << " ";
        }
        return 0;
}