#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int MN = 5e5+5;
int N, i, x, y, ans;
vi adj[MN], vec;

void dfs(int n,int p,int d){
    for(auto v : adj[n])
        if(v!=p) dfs(v,n,d+1);
    if(adj[n].size()==1) vec.push_back(d);
}

int main(){
    scanf("%d",&N);
    for(i=1;i<N;i++){
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(auto v : adj[1]){
        vec.clear();
        dfs(v, 1, 1);
        sort(vec.begin(),vec.end(),[](int i,int j){return i>j;});
        for(i=0;i<vec.size();i++) ans=max(ans,i+vec[i]);
    }
    printf("%d\n",ans);
    return 0;
}