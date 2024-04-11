#include<bits/stdc++.h>
using namespace std;
const int maxn=200007;
int t,n,p[maxn],c[maxn];
bool vis[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        cin>>n;
        for (int i=1;i<=n;++i) cin>>p[i];
        for (int i=1;i<=n;++i) cin>>c[i];
        for (int i=1;i<=n;++i) vis[i]=0;
        int ans=n;
        for (int i=1;i<=n;++i){
            if (vis[i]) continue;
            int ret=1;
            vector<int> vec;
            vec.clear();
            vis[i]=1;
            vec.push_back(i);
            for (int u=i;p[u]!=i;u=p[u]){
                ret++;
                vis[p[u]]=1;
                vec.push_back(p[u]);
            }
            for (int u=1;u<=min((int)vec.size(),ans);++u){
                if (vec.size()%u) continue;
                for (int j=0;j<u;++j){
                    bool fg=1;
                    for (int i=j;i+u<(int)vec.size();i+=u){
                        if (c[vec[i]]!=c[vec[i+u]]) fg=false;
                    }
                    if (fg) ans=min(ans,u);
                }
            }
        }
        cout<<ans<<"\n";
    }
}