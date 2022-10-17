#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e5+5;
string a[maxn], b[maxn];
int c[maxn];
int match[maxn*6], vis[maxn], used[maxn*6], vis2[maxn], deg[maxn], ok[maxn];
vector<int> g[maxn*6];
const int K = 26*26*26*26;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    auto get = [&](const string &s) {
        int ret=0;
        for(int i=0;i<s.size();++i) {
            ret=ret*26+s[i]-'a';
        }
        return ret;
    };
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=m;++i) {
        cin>>b[i]>>c[i];
        int hsh = get(b[i]);
        if(match[hsh] && match[hsh]!=c[i]) {
            cout<<"NO\n";
            return 0;
        }
        match[hsh]=c[i];
        vis[c[i]]=1;
        for(int j=0;j<k;++j) {
            if(a[c[i]][j]!='_' && a[c[i]][j]!=b[i][j]) {
                cout<<"NO\n";
                return 0;
            }
        }
    }

    queue<int> q;
    for(int i=1;i<=n;++i) {
        if(!vis[i]) continue;
        function<void(int,string&)> dfs = [&](int p, string &s) {
            if(p == k) {
                int hsh=get(s);
                if(!match[hsh]) return;
                g[i+K].push_back(hsh);
                g[hsh].push_back(i);
                deg[i]++;
                if(match[hsh]==i) ok[i]++;
                return;
            }
            if(s[p] == '_') {
                for(int j=0;j<26;++j) {
                    s[p]='a'+j;
                    dfs(p+1, s);
                    s[p]='_';
                }
            } else {
                dfs(p+1, s);
            }
        };
        dfs(0, a[i]);
        if(deg[i]==ok[i]) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()) {
        int cur=q.front(); q.pop();
        vis2[cur]=1;
        ans.push_back(cur);
        for(int u:g[cur+K]) {
            if(used[u]) continue;
            used[u]=1;
            for(int v:g[u]) {
                --deg[v];
                if(!vis2[v] && deg[v]==ok[v]) {
                    q.push(v);
                }
            }
        }
    }

    for(int i=1;i<=n;++i) {
        if(!vis[i]) ans.push_back(i);
    }
    if(ans.size() == n) {
        cout<<"YES"<<endl;
        for(int i:ans) cout<<i<<" ";cout<<endl;
    } else {
        cout<<"NO"<<endl;
    }

}