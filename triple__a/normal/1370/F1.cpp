#include<bits/stdc++.h>
using namespace std;

pair<int,int> query(vector<int> &v){
    if (v.size()==0){
        return {-1,-1};
    }
    cout<<"? "<<v.size()<<" ";
    for (auto c:v){
        cout<<c<<" ";
    }
    cout<<endl;
    int u,w;
    cin>>u>>w;
    return {u,w};
}

int t;
int n;
vector<int> g[1007];
int dis[1007];

void dfs(int u,int p){
    for (auto c:g[u]){
        if (c==p) continue;
        dis[c]=dis[u]+1;
        dfs(c,u);
    }
}

int main(){
    cin>>t;
while (t--){
    cin>>n;
    for (int i=1;i<=n;++i) g[i].clear(), dis[i]=0;
    for (int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v), g[v].push_back(u);
    }
    vector<int> v;
    for (int i=1;i<=n;++i){
        v.push_back(i);
    }
    pair<int,int> res=query(v);
    dfs(res.first,-1);
    int l=res.second/2+1,r=res.second+1,ans=res.first;
    while (l<r){
        v.clear();
        int md=(l+r)>>1;
        for (int i=1;i<=n;++i){
            if (dis[i]==md) v.push_back(i);
        }
        pair<int,int> ret=query(v);
     //   cout<<ret.second<<" "<<res.second<<endl;
        if (ret.second==res.second){
            ans=ret.first, l=md+1;
        }
        else{
            r=md;
        }
    }
    if (ans==res.first){
        v.clear();
        for (int i=1;i<=n;++i){
            if (dis[i]==l-1) v.push_back(i);
        }
        pair<int,int> ret=query(v);
        ans=ret.first;
    }
    for (int i=1;i<=n;++i) dis[i]=0;
    dfs(ans,-1);
    v.clear();
    for (int i=1;i<=n;++i){
        if (dis[i]==res.second) v.push_back(i);
    }
    pair<int,int> ret=query(v);
    cout<<"! "<<ans<<" "<<ret.first<<endl;
    string s;
    cin>>s;
    if (s!="Correct"){
        while (1){
        }
    }
}

}