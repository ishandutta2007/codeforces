#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        vector<set<int>> g(26);
        for(int i = 1; i < s.size(); ++i) {
            // s[i-1] s[i]
            int c1 = s[i-1] - 'a';
            int c2 = s[i] - 'a';
            g[c1].insert(c2);
            g[c2].insert(c1);
        }
        int ok = 1;
        vector<int> vis(26);
        for(int i = 0; i < 26; ++i) {
            if(g[i].size() > 2) {
                ok = 0;
                break;
            }
        }
        if(!ok) {
            cout << "NO" << endl;
            continue;
        }
        vector<int> ord(26);
        function<void(int)> dfs = [&](int u) {
            vis[u] = 1;
            for(int v : g[u]) {
                if(vis[v]) continue;
                ord[v] = ord[u] + 1;
                dfs(v);
            }
        };
        int rt = -1;
        for(int i = 0; i < 26; ++i) {
            if(g[i].size() == 1) {
                rt = i;
                break;
            }
        }
        if(rt != -1) {
            dfs(rt);
        } else {
            for(int i = 0; i < 26; ++i) {
                if(g[i].size()) {
                    dfs(i);
                    break;
                }
            }
        }
        vector<int> ans(26);
        iota(ans.begin(),ans.end(),0);
        sort(ans.begin(),ans.end(),[&](int i,int j){return vis[i]>vis[j] || (vis[i]==vis[j] && ord[i]<ord[j]);});
        vector<int> rpos(26);
        for(int i = 0; i < 26; ++i) {
            rpos[ans[i]] = i;
        }
        for(int i = 1; i < s.size(); ++i) {
            int c1 = s[i-1] - 'a';
            int c2 = s[i] - 'a';
            if(abs(rpos[c1] - rpos[c2]) != 1) {
                ok = 0;
                break;
            }
        }
        if(!ok) {
            cout << "NO" << endl;
            continue;
        }
        cout<<"YES"<<endl;
        for(int i:ans) cout<<(char)(i+'a');
        cout<<endl;
    }
}