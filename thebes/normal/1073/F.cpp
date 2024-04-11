#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int n, i, x, y, nd, mx, st, ans[2];
pair<int,int> a[MN], b[MN];
vector<int> adj[MN];

int dfs(int n,int p,int d){
    int sz = 0;
    for(auto v : adj[n]){
        if(v == p) continue;
        pair<int,int> tmp={dfs(v,n,d+1)+1,v};
        if(a[tmp.second].second) tmp.second=a[tmp.second].second;
        if(tmp.first>a[n].first) b[n]=a[n],a[n]=tmp;
        else if(tmp.first>b[n].first) b[n]=tmp;
        sz++;
    }
    if(sz>=2){
        if(d>mx) nd=n, mx=d;
        else if(d==mx&&a[n].first+b[n].first>a[nd].first+b[nd].first) nd=n;
    }
    return a[n].first;
}

int main(){
    for(scanf("%d",&n),i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(i=1;i<=n;i++){
        if(adj[i].size()==1){
            st = i;
            break;
        }
    }
    dfs(st, 0, 0);
    x = nd; ans[0]=a[nd].second; ans[1]=b[nd].second;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    mx = nd = 0;
    dfs(x, 0, 0);
    printf("%d %d\n%d %d\n",a[nd].second,ans[0],b[nd].second,ans[1]);
    return 0;
}