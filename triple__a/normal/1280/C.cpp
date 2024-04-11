#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int,int>

using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* DSU
int p[maxn]; // rep1(i,n) p[i]=i;

int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool unite(int u,int v){
    int pu=find(u),pv=find(v);
    p[pu]=pv;
    return pu!=pv;
}
*/

const int maxn=200007;
int n,t,sz[maxn];
vector<pair<int,int> > vec[maxn];
long long mx=0,mn=0;

void dfs1(int u,int p,int w){
    sz[u]=1;
    for (auto c:vec[u]){
        if (c.first==p) continue;
        dfs1(c.first,u,c.second);
        sz[u]+=sz[c.first];
    }
    mx+=1ll*min(sz[u],2*n-sz[u])*w;
    if (sz[u]&1) mn+=w;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while (t--){
        mn=mx=0;
        cin>>n;
        for (int i=1;i<=2*n;++i) sz[i]=0,vec[i].clear();
        for (int i=1;i<2*n;++i){
            int u,v,w;
            cin>>u>>v>>w;
            vec[u].push_back({v,w});
            vec[v].push_back({u,w});
        }
        dfs1(1,0,0);
        cout<<mn<<" "<<mx<<endl;
    }
    return 0;
}