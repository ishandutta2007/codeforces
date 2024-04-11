#include<bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
 
const int maxn=4000007;
 
vector<int> g[maxn];
ll a[maxn];
ull ans[maxn];
int p[maxn];

ull mix(ull o){
    o+=0x9e3779b97f4a7c15;
    o=(o^(o>>30))*0xbf58476d1ce4e5b9;
    o=(o^(o>>27))*0x94d049bb133111eb;
    return o^(o>>31);
}

ull hsh(int u){
    ull ret=0;
    for (auto c:g[u]){
        ret^=mix(c);
    }
    return ret;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        int n,m;
        cin>>n>>m;
        for (int i=1;i<=n;++i){
            g[i].clear();
            cin>>a[i];
        }
        while (m--){
            int u,v;
            cin>>u>>v;
            g[v].push_back(u);
        }
        for (int i=1;i<=n;++i){
            ans[i]=hsh(i), p[i]=i;
        }
        sort(p+1,p+n+1,[&](int u,int v){return ans[u]<ans[v];});
        ll sum=0;
        for (int i=1;i<=n;++i){
            if (!ans[p[i]]) continue;
            ll ret=a[p[i]];
            while (i<n&&ans[p[i]]==ans[p[i+1]]) ret+=a[p[++i]];
            sum=__gcd(ret,sum);
        }
        cout<<sum<<"\n";
    }
    return 0;
}