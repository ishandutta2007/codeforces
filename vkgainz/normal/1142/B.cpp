#include <bits/stdc++.h>
using namespace std;
#define ll long long
int seg[400005];
int n,m,q;
void create(){
    for(int i=m-1;i>=1;i--)
        seg[i] = min(seg[2*i],seg[2*i+1]);
}
int query(int l,int r){
    int res = 2e9;
    l+=m; r+=m;
    while(l<r){
        if(l%2) res = min(res,seg[l++]);
        if(r%2) res = min(res,seg[--r]);
        l/=2; r/=2;
    }
    return res;
}
int p[200001], x[200001];
int inv[200001];
vector<int> in;
vector<int> pos[200001];
bool visited[200001];
vector<int> adj[200001];
int s[200001];
void dfs2(int curr,int par){
    in.push_back(curr);
    if(in.size()>=n){
        seg[curr+m] = in[in.size()-n];
    }
    else{
        seg[curr+m] = 2e9;
    }
    for(int next : adj[curr]){
        if(next!=par){
            dfs2(next,curr);
        }
    }
    in.pop_back();

}
void dfs(int posinperm,int curridx){
    in.push_back(curridx);
    if(visited[curridx]){
        return;
    }
    visited[curridx] = true;
    int next =p[(posinperm+1)%n];
    auto nextidx = upper_bound(pos[next].begin(),pos[next].end(),curridx);
    int r = nextidx-pos[next].begin();
    if(r==pos[next].size()){
        return;
    }
    else{
        dfs((posinperm+1)%n,pos[next][r]);
    }
}
void build(){
    for(int i=0;i<m;i++){
        pos[x[i]].push_back(i);
    }
    for(int i=0;i<n;i++){
        inv[p[i]] = i;
    }
    for(int i=0;i<m;i++){
        if(!visited[i]){
            in.clear();
            dfs(inv[x[i]],i);
            for(int j=0;j<in.size()-1;j++){
                adj[in[j]].push_back(in[j+1]);
                adj[in[j+1]].push_back(in[j]);
                s[in[j]]++;
            }
            
        }
    }
    for(int i=0;i<m;i++){
        if(s[i]==0){
            in.clear();
            dfs2(i,-1);
        }
    }
    string ret = "";
    create();
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        l--;
        int min = query(l,r);
        if(min<r){
            printf("%c",'1');
        }
        else{
            printf("%c",'0');
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
        p[i]--;
    }
    for(int i=0;i<m;i++){
        scanf("%d",&x[i]);
        x[i]--;
    }
    build();
}