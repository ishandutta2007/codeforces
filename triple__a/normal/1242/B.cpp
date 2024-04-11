#include<bits/stdc++.h>
using namespace std;

const int maxn=100007;
int n,m;
set<int> vec[maxn];
bool vis[maxn];
set<int> rem;

void dfs(int u){
    vis[u]=1;
    queue<int> q;
    while (q.size()) q.pop();
    q.push(u);
    while (q.size()){
        u=q.front();
        q.pop();
        vector<int> v;
        v.clear();
        for (auto x:rem){
            if (vec[u].find(x)==vec[u].end()){
                v.push_back(x);
                q.push(x);
                vis[x]=1;
            }
        }
        for (auto c:v){
            rem.erase(c);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        vec[u].insert(v);
        vec[v].insert(u);
    }
    for (int i=1;i<=n;++i){
        rem.insert(i);
    }
    int ans=0;
    for (int i=1;i<=n;++i){
        if (vis[i]) continue;
        rem.erase(i);
        ans++;
        dfs(i);
        cout<<endl;
    }
    cout<<ans-1<<endl;
    return 0;
}