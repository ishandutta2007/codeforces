#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
vector<int> vec[maxn];
int n,cnt=1,ans[maxn];
bool vis[maxn];

bool bfs(int u){
    queue<int> q;
    q.push(u);
    vis[u]=1;
    while (q.size()){
        int u=q.front();
        q.pop();
        set<int> s;
        s.clear();
        for (auto c:vec[u]){
            if (!vis[c]){
                s.insert(c);
            }
        }
        while (s.size()){
            if (s.find(ans[++cnt])==s.end()) return false;
            q.push(ans[cnt]);
            vis[ans[cnt]]=1;
            s.erase(ans[cnt]);
        }
    }
    return true;
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);    
    }
    for (int i=1;i<=n;++i){
        scanf("%d",&ans[i]);
    }
    if (bfs(1)){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}