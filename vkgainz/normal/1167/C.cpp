#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> in;
bool visited[500001];
vector<int> adj[500001];
int ans[500001];
void dfs(int i){
    in.push_back(i);
    visited[i] = true;
    for(int next : adj[i])
        if(!visited[next]) dfs(next);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int c; scanf("%d",&c);
        vector<int> temp;
        for(int i=0;i<c;i++){
            int curr; scanf("%d",&curr);
            curr--;
            temp.push_back(curr);
        }
        for(int i=0;i<c-1;i++){
            adj[temp[i]].push_back(temp[i+1]);
            adj[temp[i+1]].push_back(temp[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            in.clear();
            dfs(i);
            for(auto &it : in)
                ans[it] = in.size();
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }
}