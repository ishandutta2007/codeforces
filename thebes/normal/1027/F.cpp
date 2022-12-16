#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

const int MN = 1e6+6;
int n, i, x, y, d[MN], vis[2*MN][2], ans, t[2*MN];
vector<pair<int,int>> adj[2*MN];
pair<int,int> arr[MN];
map<int,int> mp;
vector<int> vec;
queue<int> q;

int dfs(int n){
    int f = 1; vis[n][0] = 1;
    for(auto v : adj[n]){
        if(!d[v.second]) f--,d[v.second]=1;
        if(!vis[v.first][0]) f+=dfs(v.first);
    }
    return f;
}

inline void bfs(int src,int &A,int &B){
    q.push(src); vis[src][1]=1;
    A = t[src], B = 0;
    while(q.size()){
        int cur = q.front(); q.pop();
        if(t[cur]>A) B=A, A=t[cur];
        else if(t[cur]>B) B=t[cur];
        for(auto v : adj[cur]){
            if(!vis[v.first][1]){
                vis[v.first][1] = 1;
                q.push(v.first);
            }
        }
    }
}

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d%d",&arr[i].F,&arr[i].S);
        mp[arr[i].F]=mp[arr[i].S]=0;
    }
    i=0; auto it=mp.begin();
    for(;it!=mp.end();it++)
        it->second=++i,t[i]=it->first;
    for(i=1;i<=n;i++){
        arr[i].F = mp[arr[i].F];
        arr[i].S = mp[arr[i].S];
        adj[arr[i].F].push_back({arr[i].S,i});
        adj[arr[i].S].push_back({arr[i].F,i});
    }
    for(i=1;i<=mp.size();i++){
        if(vis[i][0]) continue;
        int tmp = dfs(i);
        if(tmp < 0){
            printf("-1\n");
            return 0;
        }
        else {
            int a, b; bfs(i, a, b);
            ans = max(ans, ((tmp==0)? a : b));
        }
    }
    printf("%d\n",ans);
    return 0;
}