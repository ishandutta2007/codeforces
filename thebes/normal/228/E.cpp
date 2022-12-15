#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int MN = 105;
int N, M, i, x, y, w, ans[MN], c;
vector<pii> adj[MN];
vector<int> s;

void solve(int n){
    if(ans[n]) s.push_back(n);
    for(auto v : adj[n]){
        if(ans[v.first]==-1){
            ans[v.first] = ans[n]^v.second;
            solve(v.first);
        }
        if(ans[v.first]!=ans[n]^v.second)
            c = 1;
    }
}

int main(){
    memset(ans, -1, sizeof(ans));
    for(scanf("%d%d",&N,&M),i=1;i<=M;i++){
        scanf("%d%d%d",&x,&y,&w);
        adj[x].push_back({y,!w});
        adj[y].push_back({x,!w});
    }
    for(i=1;i<=N;i++){
        if(ans[i]==-1) ans[i]=0, solve(i);
    }
    if(c) printf("Impossible\n");
    else{
        printf("%d\n",s.size());
        for(auto v : s) printf("%d ",v);
    }
    return 0;
}