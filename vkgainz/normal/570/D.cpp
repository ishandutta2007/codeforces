#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
struct query{
    int h,idx;
    query(int x,int y){
        h = x, idx = y;
    }
};
int n,m;
string s;
vector<int> adj[500001];
vector<query> q[500001];
bool ans[500001];
int depth[500001];
map<int,map<int,int>> col[500001]; //maybe use unordered?
void dfs(int curr,int par){
    ++col[curr][depth[curr]][s[curr]-'a'];
    for(int next : adj[curr]) if(next!=par){
        depth[next] = depth[curr]+1;
        dfs(next,curr);
        if(col[next].size()>col[curr].size()) swap(col[curr],col[next]);
        for(auto &it : col[next]){
            for(auto x : it.second) col[curr][it.first][x.first]+=x.second;
        }
        col[next].clear();
    }
    for(query x : q[curr]){
        int numOdd = 0;
        for(auto x : col[curr][x.h]) numOdd+=(x.second%2);
        if(numOdd<=1) ans[x.idx] = 1;
        else ans[x.idx] = 0;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n-1;i++){
        int p;scanf("%d",&p);
        --p;
        adj[i+1].push_back(p);
        adj[p].push_back(i+1);
    }
    cin >> s;
    for(int i=0;i<m;i++){
        int v,h; scanf("%d%d",&v,&h);
        --v;
        q[v].push_back({h,i});
    }
    depth[0] = 1;
    dfs(0,-1);
    for(int i=0;i<m;i++) {
        if(ans[i]==1) printf("Yes\n");
        else printf("No\n");
    }
}