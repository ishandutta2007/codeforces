#include <bits/stdc++.h>
using namespace std;

#define pub push_back

#define rep(i,a,b) for(int i=a;i<=b;i++)

int n;
int a[200005];
int b[200005];
int c[200005];
vector<int> g[200005];

int tin[200005];
int tout[200005];
int nxt;

void dfs(int u,int p){
    tin[u]=++nxt;
    for(int v:g[u])if(v!=p)dfs(v,u);
    tout[u]=nxt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(ios::badbit | ios::failbit);

    cin>>n;
    rep(i,0,n-1)cin>>a[i]>>b[i]>>c[i];

    rep(i,1,n-1){
        int u,v;cin>>u>>v;
        --u,--v;
        g[u].pub(v);g[v].pub(u);
    }

    dfs(0,0);

    vector<int> ord;ord.resize(n);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int i,int j){return a[i]<a[j];});

    set<int> s01,s10;
    rep(i,0,n-1){
        if(b[i]==0&&c[i]==1)s01.insert(tin[i]);
        if(b[i]==1&&c[i]==0)s10.insert(tin[i]);
    }

    long long ans=0;
    for(int i:ord){
        while(true){
            auto it01=s01.lower_bound(tin[i]);
            auto it10=s10.lower_bound(tin[i]);
            if(it01==s01.end())break;
            if(it10==s10.end())break;
            if(*it01>tout[i])break;
            if(*it10>tout[i])break;
            ans+=2*a[i];
            s01.erase(it01);
            s10.erase(it10);
        }
    }
    if(!s01.empty()||!s10.empty())cout<<-1;
    else cout<<ans;
}