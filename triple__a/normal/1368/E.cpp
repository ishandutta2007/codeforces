#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
int c[maxn];
int n,m,t;
vector<int> g[maxn];
vector<int> ans;
int main(){
    cin>>t;
    while (t--){
        ans.clear();
        cin>>n>>m;
        for (int i=1;i<=n;++i) g[i].clear();
        for (int i=1;i<=m;++i){
            int u,v;
            cin>>u>>v;
            g[v].push_back(u);
        }
        for (int i=1;i<=n;++i){
            int res=0;
            for (auto d:g[i]) res=max(c[d],res);
            c[i]=(res+1)%3;
            if (!c[i]) ans.push_back(i);
//            cout<<c[i]<<" ";
        }
        cout<<ans.size()<<" ";
        for (auto c:ans) cout<<c<<" ";

    }
}