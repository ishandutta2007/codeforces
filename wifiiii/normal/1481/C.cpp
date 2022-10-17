#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        vector<int> a(n),b(n),c(m),ans(m);
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i) cin>>b[i];
        for(int i=0;i<m;++i) cin>>c[i];
        vector<int> vis(n+1);
        vector<vector<int>> g(n+1);
        for(int i=0;i<n;++i) {
            if(a[i]!=b[i]) {
                g[b[i]].push_back(i);
            }
            vis[b[i]]=1;
        }
        if(!vis[c.back()]) {
            cout<<"NO"<<'\n';
            continue;
        }
        int ok=1;
        for(int i=0;i<m;++i) {
            if(g[c[i]].size()) {
                int p=g[c[i]].back(); g[c[i]].pop_back();
                ans[i]=p+1;
            }
        }
        for(int i=1;i<=n;++i) if(g[i].size()) ok=0;
        if(!ok) {
            cout<<"NO"<<'\n';
            continue;
        }
        if(ans.back()) {
            for(int &i : ans) if(!i) i = ans.back();
        } else {
            int pos=find(b.begin(), b.end(), c.back())-b.begin()+1;
            for(int &i : ans) if(!i) i = pos;
        }
        cout<<"YES"<<'\n';
        for(int i:ans) cout<<i<<" ";
        cout<<'\n';
    }
}