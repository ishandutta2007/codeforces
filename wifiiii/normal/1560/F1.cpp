#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        vector<int> vis(10);
        int mx = -1, mn = 10, cnt = 0;
        for(int i = 0; i < s.size(); ++i) {
            int f = 0;
            while(cnt == k && !vis[s[i] - '0']) ++s[i], f = 1;
            if(!vis[s[i] - '0']) ++cnt;
            vis[s[i] - '0']++;
            if(cnt == k) {
                if(!f && s[i] < '9') {
                    int ok = 1;
                    int nxt = max(mx, s[i] - '0');
                    for(int j = i + 1; j < s.size(); ++j) {
                        if(nxt < s[j] - '0') {
                            ok = 0;
                            break;
                        }
                        if(nxt > s[j] - '0') {
                            break;
                        }
                    }
                    if(!ok) {
                        if(vis[s[i] - '0'] == 1) --cnt;
                        vis[s[i] - '0']--;
                        ++s[i];
                        f = 1;
                    }
                }
                if(f && cnt == k) {
                    while(!vis[s[i] - '0']) ++s[i];
                }
            }
            mx = max(mx, s[i] - '0');
            mn = min(mn, s[i] - '0');
            if(f) {
                if(set<char>(s.begin(), s.begin() + i + 1).size() < k) mn = 0;
                for(int j = i + 1; j < s.size(); ++j) {
                    s[j] = mn + '0';
                }
                break;
            }
        }
        cout << s << endl;
    }
}